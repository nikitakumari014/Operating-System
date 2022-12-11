#include <bits/stdc++.h>
using namespace std;
int pagefaults(int pages[], int n, int frames)
{
    unordered_set<int> s;
    queue<int> index;
    int pages_faults = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s.size() < frames)
        {
            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);
                pages_faults++;
                index.push(pages[i]);
            }
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int curr = index.front();
                index.pop();
                s.erase(curr);
                s.insert(pages[i]);
                index.push(pages[i]);
                pages_faults++;
            }
        }
    }
    return pages_faults;
}
int main()
{
    int n;
    cout << "Enter the number of pages: \n";
    cin >> n;
    int pages[n];
    cout << "Enter pages: \n";
    for (int i = 0; i < n; i++)
        cin >> pages[i];
    // int pages[n] = {7, 0, 1, 3, 2, 5, 3, 1, 2, 0, 1, 0};
    int frames;
    cout << "Enter frame size: \n";
    cin >> frames;
    // int frames = 4;
    cout << " Total pages faults = " << pagefaults(pages, n, frames);
    return 0;
}
// if cpu demands for a new page but that is absent in the main memory,
// that is called page fault.
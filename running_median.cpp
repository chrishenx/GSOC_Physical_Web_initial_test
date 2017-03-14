/*
    Compute the median of a set of incoming integers from a stream

    @author Christian Gonzalez Leon
    @date March 13th, 2017
*/

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Given that v is sorted in ascending mode
float compute_median(const vector<int>& v)
{
    const int L = v.size() - 1;
    float median = v[L / 2];
    if (L % 2 != 0) {
        median = 0.5 * (median + v[L / 2 + 1]);
    }
    return median;
}

int main()
{
    // Read from standard input
    int elems_count;
    int elem;
    vector<int> v;
    cin >> elems_count;

    cout << std::setprecision(2) << std::fixed;

    while (elems_count-- > 0) {
        cin >> elem;
        v.push_back(elem);
        sort(v.begin(), v.end());
        float median = compute_median(v);
        cout << median << endl;
    }

    return 0;
}

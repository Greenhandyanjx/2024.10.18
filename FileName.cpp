#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<numeric>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& nums) {

    }
};
class Solution{
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};

class Solution {
public:
    int find_s(vector<int>& arr, int x) {
        if (x < arr[0])return 0;
        else if (x > arr.back())return arr.size() - 1;
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] < x) {
                right = mid;
            }
            else if (arr[mid] > x) {
                left = mid + 1;
            }
            else return mid;
        }
        return left;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int index = find_s(arr, x);
        int left = index, right = index + 1;
        vector<int>res;
        if (index == 0)return vector<int>(arr.begin(), arr.begin() + k);
        if (index == arr.size()-1)return vector<int>(arr.end()-k, arr.end());
        while (left >= 0 && right < arr.size() && k--) {
            if (x - arr[left] < arr[right] - x)res.push_back(arr[left--]);
            else if (x - arr[left] > arr[right] - x)res.push_back(arr[right++]);
            else res.push_back(arr[left--]);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
class Solution {
public:
    using PCI = pair<char, int>;
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int>mp;
        for (auto& i : tasks)mp[i]++;
        int cnt = 0,mv=0;
        for (auto& p : mp) {
            if (p.second > mv) {
                cnt = 0;
                cnt++;
                mv = p.second;
            }
            else if (p.second == mv)cnt++;
        }
        int res = cnt + (mv - 1) * (n + 1);
        int size = tasks.size();
        return max(size, res);
    }
};
class Solution {
public:
    using PCI = pair<char, int>;
    string frequencySort(string s) {
        unordered_map<char, int>mp;
        for (auto& i : s)mp[i]++;
        vector<PCI>vec;
        for (auto& p : mp)vec.push_back({ p.first,p.second });
        auto cmp = [](PCI& p1, PCI& p2) {return p1.second > p2.second; };
        sort(vec.begin(), vec.end(), cmp);
        string res="";
        for (auto& p : vec) {
            string temp(p.second, p.first);
            res += temp;
        }
        return res;
    }
};
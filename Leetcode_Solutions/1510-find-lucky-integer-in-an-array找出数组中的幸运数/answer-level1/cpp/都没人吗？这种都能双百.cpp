class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> temp;
        temp = arr;
        sort(arr.rbegin(),arr.rend());
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
        int size = arr.size();
        if(size == 0) return -1;
        for(int i=0;i<size;i++){
            if(arr[i] == count(temp.begin(),temp.end(),arr[i])){
                return arr[i];
            }
        }
        return -1;

    }
};
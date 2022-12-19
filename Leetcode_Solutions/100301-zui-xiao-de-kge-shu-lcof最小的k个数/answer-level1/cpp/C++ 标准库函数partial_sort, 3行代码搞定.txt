    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        partial_sort(arr.begin(), arr.begin() + k, arr.end());
        vector<int> result(arr.begin(), arr.begin() + k);
        return result;
    }

partial_sort保证前k个数是有序的，后面不保证，高度匹配本题
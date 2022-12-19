
    [1,2,3,1]  看来不行，因为最小值，可能是跨区间拼接出来 
    */
    string divide(vector<int>& nums, int l, int r) {

        if (l == r) return to_string(nums[l]); // base


        // divide
        int mid = l + (r-l) / 2;
        string ls = divide(nums, l, mid);
        string rs = divide(nums, mid+1, r);

        // merge
        if ((ls + rs) < (rs + ls)) {
            return ls + rs;
        } else {
            return rs + ls;
        }

        return "";
/*
        long long lr = stoll(ls + rs);
        long long rl = stoll(rs + ls);

        return lr < rl ? (ls + rs) : (rs + ls);
        */
    }
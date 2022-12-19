class Solution {
public:
    int find(int x,int f[])
    {
        if(f[x]!=x) f[x] = find(f[x],f);
        return f[x];
    }
    int minSwapsCouples(vector<int>& row) {
        int sum = row.size();
        int groups = sum>>1;
        int f[sum];
        for(int i=0;i<sum;i++)
        {
            f[i] = i;
            f[i+1] = i;
            i++;
        }
        for(int i=0;i<sum;i++)
        {
            int a = find(row[i],f);
            int b = find(row[i+1],f);
            if(a!=b) f[b] = a;
            i++;
        }
        unordered_map<int,int> map;
        int ans = 0;
        for(int i=0;i<sum;i++)
        {
            int a = find(row[i],f);
            if(!map.count(a))
            {
                map[a] = 1;
                ans++;
            }
            else map[a]++;
        }
        return groups - ans;
    }
};
```
    int findTheDistanceValue(vector<int>& a1, vector<int>& a2, int d) {
        int n1 = a1.size(), n2 = a2.size();
        sort(a2.begin(),a2.end());
        int res = 0;
        for(int i = 0; i < n1; i++){
            int l = 0, r = n2-1;
            while(l < r){ //在a2中查找>=a1[i] 最小的一个
                int mid = l + r >>1;
                if(a2[mid]>=a1[i]) r = mid;
                else l = mid + 1;
            }
            int x = a2[r], y = a2[max(0,r-1)], z = a2[min(r+1,n2-1)];//a2中 可能差<=d的三个数 
                                    //若这三个数都不行,其余数就更不行了,因为这三个数是最接近目标的数了
            if(!(abs(a1[i]-x)<=d||abs(a1[i]-y)<=d||abs(a1[i]-z)<=d)) res++;
        }
        return res;
    }
```

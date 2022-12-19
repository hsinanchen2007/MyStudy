## 直接排序后选择
```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        if(k==0){
            return {};
        }
        vector<int> res(arr.begin(),arr.begin()+k);
        return res;
    }
};
```

## 使用堆排序
```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if(k == 0){
            return res;
        }
        priority_queue<int> h;
        for(int num : arr){
            if(h.size() < k){
                h.push(num);
            }else{
                if(h.top() <= num){
                    continue;
                }else{
                    h.pop();
                    h.push(num);
                }
            }
        }
        while(!h.empty()){
            res.push_back(h.top());
            h.pop();
        }
        return res;
    }
};
```

## BFPRT算法
```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k==0){
            return {};
        }
        BFPRT(arr,0,arr.size()-1,k);
        vector<int> res(arr.begin(),arr.begin()+k);
        return res;
    }
    //插入排序
    void insert_sort(vector<int>& arr,int l,int r){
        for(int i=l+1;i<=r;i++){
            if(arr[i-1]>arr[i]){
                int t=arr[i];
                int j=i;
                while(j>l && arr[j-1]>t){
                    arr[j]=arr[j-1];
                    j--;
                }
                arr[j]=t;
            }
        }
    }

    //寻找中位数的中位数
    int find_mid(vector<int>& arr,int l,int r){
        if(l==r){
            return l;
        }
        int i=0,n=0;
        for(i=l;i<r-5;i+=5){
            insert_sort(arr,i,i+4);
            n=i-l;
            swap(arr[l+n/5],arr[i+2]);
        }

        int num=r-i+1;
        if(num>0){
            insert_sort(arr,i,i+num-1);
            n=i-l;
            swap(arr[l+n/5],arr[i+num/2]);
        }
        n=n/5;
        if(n==l){
            return l;
        }
        return find_mid(arr,l,l+n);
    }

    //进行划分过程
    int partion(vector<int>& arr,int l,int r,int p){
        swap(arr[p],arr[l]);
        int i=l;
        int j=r;
        int pivot=arr[l];
        while(i<j){
            while(arr[j]>=pivot && i<j){
                j--;
            }
            arr[i]=arr[j];
            while(arr[i]<=pivot && i<j){
                i++;
            }
            arr[j]=arr[i];
        }
        arr[i]=pivot;
        return i;
    }

    int BFPRT(vector<int>& arr,int l,int r,int k){
        int p=find_mid(arr,l,r);
        int i=partion(arr,l,r,p);

        int m=i-l+1;
        if(m==k){
            return arr[i];
        }
        if(m>k){
            return BFPRT(arr,l,i-1,k);
        }
        return BFPRT(arr,i+1,r,k-m);
    }
};
```

![图片.png](https://pic.leetcode-cn.com/75393eb166f421ff49cfc798d402ac57492bd4cb809e31b354b880882324026c-%E5%9B%BE%E7%89%87.png)

有关BFPRT算法可以参考我的博客，[传送门](https://www.jianshu.com/p/83bb10ad1d32)。

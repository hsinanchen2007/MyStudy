![image.png](https://pic.leetcode-cn.com/d9aff162b2038ed3d806b90e1fd9491decdbf7297f1db230e9adf98fab7d357b-image.png)
解题思路：用两个数组分别保存不符合要求的奇偶坐标，交换。
```
    vector<int> sortArrayByParityII(vector<int>& A) {
        int tmp = 0;
        vector<int> tmpodd = {};
        vector<int> tmpeve = {};
        for(int i =0;i<A.size();++i){
            if(i%2 ==0 && A[i]%2 !=0){
                   tmpodd.push_back(i);            
            } else if(i%2 !=0 && A[i]%2 ==0){
                   tmpeve.push_back(i);
            }
        }
        for(int j =0;j<tmpodd.size();++j){

                     tmp = A[tmpodd[j]];
            A[tmpodd[j]] = A[tmpeve[j]];
            A[tmpeve[j]] = tmp;
        } 
        return A;       
    }
```


### 解题思路
bitmap遍历
![捕获.PNG](https://pic.leetcode-cn.com/61791dca6047c93b5bcc8c5c5b3949a32a942238e3782681bddd07683693b111-%E6%8D%95%E8%8E%B7.PNG)


### 代码

```cpp
class Solution {
public:
    int maxLength(vector<string>& arr) {
        for(auto s:arr)
        {
            if(s == ""){
                continue;
            }
            uint32_t bitmap = 0;
            bool flag = false;
            for(auto c:s){
                int bitNo = c-'a';
                uint32_t bitval =  (1<<bitNo);
                if((bitmap & bitval) >0)
                {
                    flag = true;
                    break;
                } else{
                    bitmap = bitmap | bitval;
                }
            }
            if(flag == true){
                continue;
            }else {
                arr_.push_back(bitmap);
            }
        }
        int size = arr_.size();
        int loopNum = (1<<size);
        for(uint32_t i = 1;i<loopNum;i++){
            uint32_t bitsum = 0;
            for(int j=0; j<size;j++){
                uint32_t bitval =  (1<<j);
                if((bitval & i) >0){
                    uint32_t bitmap = arr_[j];
                    if((bitsum & bitmap)> 0 ){
                        bitsum = 0;
                        break;
                    }else{
                       bitsum = bitsum | bitmap;
                    }
                }
            }
            int count=0;
            while(bitsum>0){
                if(bitsum%2 >0){
                    count++;
                }
                bitsum = bitsum/2;
            }
            ans = count > ans? count: ans;
        }
        return ans;
    }
private :
    vector<uint32_t> arr_;
    int ans = 0;
};
```
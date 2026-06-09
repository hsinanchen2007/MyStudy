该题只要判断是否可以达到索引最后一个解，无法达到最后一个解的原因是在于'0'，如果我们可以把所有的'0'索引位置捞出来，并判断这些'0'索引位置是否都可以正常跳过去，即可以达到nums数组的最后一个返回true，代码如下：
```
            bool canJump(vector<int>& nums) {
                vector<int> zeroIndexs ;
                if(nums.size()==1 || nums.size()==0){
                    return true;
                }
                for(int i=0;i<nums.size()-1;i++){
                    if(nums[i]==0){
                        zeroIndexs.push_back(i);
                    }
                }
                if(zeroIndexs.size()==0){
                    return true;
                }
                if(zeroIndexs[0]==0){
                    return false;
                }
                for(int i=0;i<zeroIndexs.size();i++){
                    int temp = 2;
                    bool flag = false;
                    for(int j=zeroIndexs[i]-1;j>=0;j--){
                        if(nums[j]>=temp){
                            flag=true;
                            break;
                        }
                        temp++;
                    }
                    if(flag==false){
                        return false;
                    }
                }
                return true;    
            }
```

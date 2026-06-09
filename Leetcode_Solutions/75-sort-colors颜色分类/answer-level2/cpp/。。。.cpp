### 解题思路
从数组后面确定两个标识符end2和end1，分别表示2序列的结束和1序列的结束，然后从前面遍历。
代码明显可以优化的
### 代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int end2 = -1;
        int end1 = -1;
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            if(nums[i]==2){
                if(end1==-1) end2 = i;
                else {
                    break;
                }
            }
            else if (nums[i]==1){
                end1 = i;
            }
            else{
                break;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(i>=end1&&end1!=-1){
                break;
            }
            if(nums[i]==0) continue;
            else if(nums[i]==1){
                if(end1==-1){
                    if(end2==-1){
                        swap(nums[i],nums[n-1]);
                        end1 = n-1;
                    }
                    else{
                        for(int j=end2-1;j>i;j--){
                            if(nums[j]==2){
                                swap(nums[j],nums[end2-1]);
                                end2--;
                                end1--;
                            }
                            else if(nums[j]==1){
                                end1 = j;
                            }
                            else{
                                swap(nums[i],nums[j]);
                                end1 = j;
                                break;
                            }
                        }
//                        swap(nums[i],nums[end2-1]);
//                        end1 = end2-1;
                    }
                }
                else{
                    for(int j=end1-1;j>i;j--){
                        if(nums[j]==2){
                            if(end2!=-1){
                                swap(nums[j], nums[end2-1]);
                                
                                end2--;
                                end1--;
                            }
                            else{
                                swap(nums[j],nums[n-1]);
                                end2 = n-1;
                                end1 = j;
                            }
                        }
                        else if(nums[j]==0){
                            swap(nums[i], nums[j]);
                            end1--;
                            break;
                        }
                        else{
                            end1--;
                        }
                    }
                }
            }
            else{
                if(end2==-1){
                    if(end1==-1){
                        swap(nums[i], nums[n-1]);
                        end2 = n-1;
                    
                    }
                    else{
                        swap(nums[i],nums[n-1]);
                        end2 = n-1;
                        for(int j=end1-1;j>i;j--){
                            if(nums[j]==2){
                                swap(nums[j], nums[end2-1]);
                                end2--;
                                end1 = j;
                            }
                            else if (nums[j]==0){
                                swap(nums[i], nums[j]);
                                end1 = j;
                                break;
                            }
                            else{
                                end1--;
                            }
                        }
                    }
                }
                else{
                    if(end1==-1){
                        for(int j=end2-1;j>i;j--){
                            if(nums[j]==2){
                                end2--;
                                continue;
                            }
                            else if (nums[j]==1){
                                swap(nums[i],nums[j]);
                                end2--;
                                for(int x=j-1;x>i;x--){
                                    if(nums[x]==2){
                                        if(end1==-1){
                                            end2--;
                                            continue;
                                        }
                                        else{
                                            swap(nums[x],nums[end2-1]);
                                            end2--;
                                            end1--;
                                        }
                                    }
                                    else if (nums[x]==1){
                                        end1 = x;
                                    }
                                    else{
                                        swap(nums[i], nums[x]);
                                        end1 = x;
                                        break;
                                    }
                                }
                                break;
                            }
                            else{
                                swap(nums[i], nums[j]);
                                end2 = j;
                                break;
                            }
                        }
                    }
                    else{
                        swap(nums[i],nums[end2-1]);
                        end2--;
                        for(int j=end1-1;j>i;j--){
                            if(nums[j]==2){
                                swap(nums[j],nums[end2-1]);
                                end2--;
                                continue;
                            }
                            else if(nums[j]==1){
                                end1--;
                            }
                            else{
                                swap(nums[i],nums[j]);
                                end1 = j;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
};
```

添加一个优秀题解，跟我的代码执行情况一样的，但是代码量天差地别..
```cpp
class Solution{
public:
    void sortColors(vector<int>& nums){
        int size = nums.size();
        if(size<2){
            return;
        }
        int zero = 0;
        int two = size;
        int i = 0;
        while (i<two) {
            if(nums[i]==0){
                swap(nums[zero],nums[i]);
                zero++;
                i++;
            }else if(nums[i]==1){
                i++;
            }else{
                two--;
                swap(nums[i],nums[two]);
            }
        }
    }
};
```

![360截图20200321205521811.jpg](https://pic.leetcode-cn.com/d1c5d371d45ba08483d0d91e5a53dbd2d5094ee445582a0ad9075ddae3fa30ca-360%E6%88%AA%E5%9B%BE20200321205521811.jpg)
先考虑特殊情况。
比如长度小于3时，一定return true;
比如当需要修改的数在最后一个，一定return true;
遍历两遍，第一遍修改数组中不符合非递减的元素，修改后结束循环；
第二遍重新遍历，若仍有不符合题意得元素，则返回false;

其中，第一遍循环中，当检测出异常元素，即发现nums[i]>nums[i+1];
说明nums[i+1]是偏小了
而nums[i+1]小到什么程度，决定要修改的元素是谁
如果nums[i+1]比nums[i-1]小，（nums[i+1]非常小）比如nums[i-1,i,i+1]=1，3，-2
那么讲nums[i+1]调到nums[i]即可
否则，即nums[i+1]>nums[i-1]，（nums[i+1]不是非常小，至少比nums[i-1]大-T-）又由nums[i]>nums[i+1]得nums[i]>nums[i+1]>nums[i-1]
如nums[i-1,i,i+1]=1，5，4
那就要比较nums[i+1]和nums[i+2]
若nums[i+1]<=nums[i+2],如nums[i-1,i,i+1,i+2]=1，5，4,5， 那把nums[i]改小点还可能符合题意
否则，即nums[i+1]>nums[i+2],如nums[i-1,i,i+1,i+2]=1，5，4,3，出现了3个连续递减的，直接返回false就可

第一遍结束，将只存在的一个的非正常元素的连续3个元素改成非递减元素了
第二遍就检查还有没有非正常元素了

bool checkPossibility(int* nums, int numsSize){
    int i=0;
    int cnt=0;
    if(numsSize<3)return true;
    for(;i<numsSize-1;i++)
    {  
        if(nums[0]>nums[1]){nums[0]=nums[1];cnt++;break;}
        if(i==numsSize-2){return true;}
        if(nums[i]>nums[i+1])//出现不正常元素，即该元素大于后面的元素
        {
            if(nums[i-1]<=nums[i+1]){//两边的两个元素符合非递增，则中间的元素大于两边的
                                    //如nums[i-1,i,i+1]=1,4,3
                nums[i]=nums[i-1];
                cnt++;
                break;
            }
            else if(nums[i+1]<=nums[i+2])//中间的元素nums[i+1]小于两边的元素
                                        //如nums[i-1,i,i+1,i+2]=3,5,2,3
            {
                nums[i+1]=nums[i];
                cnt++;
                break;
            }else return false;
        }
    }    
    for(i=0;i<numsSize-1;i++)
    {
        if(nums[i]>nums[i+1])
        {
            cnt++;
            break;
        }
    }
    if(cnt==2)return false;
    return true;

# }
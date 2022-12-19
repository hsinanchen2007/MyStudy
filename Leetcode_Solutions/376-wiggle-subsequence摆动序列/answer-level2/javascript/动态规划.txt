### 解题思路
* 状态转移方程：F(n)=F(n-1)+T(n-1)&&(nums[n]-nums[n-1])取决于后面是否为负若为负则为F(n-1)+1
* T(n)相应的和nums[n]-nums[n-1]对应
    + 以上F(n)表示长度为n的数组的最大摆动序列的长度，T(n)表示该最大摆动序列的最后两个相减的正负。
* 利用一个辅助数组``helper``记录所有情况
    + 测试的时候对类似于[3,3,3,2,5]的测试用例进行了特殊处理
    + 其他非头部情况下的``相等情况``均按``不可取``处理
* 复杂度分析：
    + 时间复杂度：O(n)
    + 空间复杂度：O(n)

### 代码

```javascript
const wiggleMaxLength = nums=>{
    let helper=[];
    if(nums.length<2) return nums.length;
    if(nums.length===2){
        return nums[1]-nums[0]===0?1:2;
    }
    helper[0]={num:1,flag:1};
    // 主要用来解决类似于[3,3,3,2,5]的测试用例
    while(nums[1]-nums[0]===0){
        nums.splice(1,1);
    }
    helper[1]={num:nums[1]-nums[0]===0?1:2,flag:nums[1] - nums[0] > 0?1:-1};
    for(let i=2;i<nums.length;i++){
        let check=(helper[i-1].flag)*(nums[i]-nums[i-1]);
        // console.info('check==>',check);
        if(check<0){
            // 可取
            helper[i]={num:helper[i-1].num+1,flag:(nums[i] - nums[i-1] > 0?1:-1)};
        }else{
            // 不可取
            helper[i]={num:helper[i-1].num,flag:helper[i-1].flag};
        }
    }
    // console.info(helper);
    return helper[nums.length-1].num;
};
```
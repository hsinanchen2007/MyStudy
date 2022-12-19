### 解题思路
经典回溯法，代码清晰简洁。97%

### 代码

```java
public class Solution {

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);//对数组排序，当当前数字与累加得到的数据大于目标值，后面的值就不用再考虑了
        List<List<Integer>> result=new ArrayList<>();
        List<Integer> list=new ArrayList<>();
        back(candidates,0,result,target,0,list);
        return result;
    }
     /**
     * 
     * @param nums//传递数组    
     * @param begin//传递下一层搜索的起始位置
     * @param result//传递结果集合
     * @param target//传递目标值
     * @param count//传递累加的结果与target作比较
     * @param list//保存遍历路劲数字
     */
    private void back(int[] nums,int begin,List result,int target,int count,List list){

        if(target==count){//出口
            result.add(list);return;
        }
        
        for(int i=begin;i<nums.length;i++){
            int s=nums[i]+count;
            if(s<=target){//count与当前节点相加小于目标值就将当前节点加到list里面
                list.add(nums[i]);
                back(nums,i,result,target,s,new ArrayList(list));//因为list是引用类型，所以要使用新的空间
                list.remove(list.size()-1);//回退
            }
            else {
                break;
            }
        }

    }
}
```
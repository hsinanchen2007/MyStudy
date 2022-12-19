![360截图17001018474358.png](https://pic.leetcode-cn.com/d699413f87ed47e2b9d70b0e46a45e3047c6d2c8cef8e2b1d8a4ee8a2c5a6650-360%E6%88%AA%E5%9B%BE17001018474358.png)


### 代码

```java
class Solution {
    List<List<Integer>> res=new ArrayList<>();
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);//先排序，重复的元素放在一起，便于去重
        int sum=0;
        int visit[]=new int[nums.length];//用visit数组跳过重复元素
        backtrack(visit,nums,new ArrayList<>(),target,0,sum);

        return res;
    }

    private  void backtrack(int[] visit, int[] nums, ArrayList<Integer> temp,int target,int start,int sum) {
        if(temp.size()==4&&sum==target){
            res.add(new ArrayList<>(temp));return;//temp保存所有符合条件的数组
        }
        if(temp.size()==4&&sum!=target){
          return;//如果四个元素和不等于target，直接返回上一层3个元素，遍历下一个第四个元素
        }


        for(int i=start;i<nums.length;i++){
            if(visit[i]==1||(i>0&&nums[i]==nums[i-1]&&visit[i-1]==0)) continue;//跳过重复元素，visit[i-1]==0表示两个相同元素的前一个已经被取过，后一个就不用再取。
            if(temp.size()==3&&sum+nums[i]>target){//如果加上第四个位置，已经比target大，就没必要再去遍历完第四个位置剩下的，因为已经排过序，剩下的肯定更大，直接返回第三个位置。
                return;
            }
            temp.add(nums[i]);
            visit[i]=1;
            backtrack(visit,nums,temp,target,i+1,sum+nums[i]);
            visit[i]=0;
            temp.remove(temp.size()-1);
        }
    }
}
```
- nums转list, 用于插入删除方便
- 使用递归回溯暴力遍历更新res
# 47. 全排列 II(有重复数字)
```java
定一个有重复数字的序列, 返回全排序
*/
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
    	List<Integer> list=new ArrayList<Integer>();
    	Arrays.sort(nums);// 从小到大排序
    	for(int i:nums) {
    		list.add(i);
    	}
    	List<List<Integer>> res=new ArrayList();
    	recur(res,list,new ArrayList<Integer>());
    	return res;
    }

	private void recur(List<List<Integer>> res, List<Integer> nums, ArrayList<Integer> tmp) {
		if(nums.size()==0) {
			res.add(new ArrayList<Integer>(tmp));
			return;
		}
		// 还没有都用完
		for(int i=0;i<nums.size();i++) {
			// 删
			Integer integer = nums.get(i);
            // 去重, 找到最后那个重复的数
			while(nums.size()>i&&nums.get(i)==integer) {
				i++;
			}i--;// 减多了
			nums.remove(i);
			// 加
			tmp.add(integer);
			// 递归
			recur(res,nums,tmp);
			// 删最后一个
			tmp.remove(tmp.size()-1);//
			// 加回去
			nums.add(i,integer);
		}
	}
}
```
# 46. 全排列
```java
/*
给定一个 没有重复 数字的序列，返回其所有可能的全排列。
*/
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        // 初始化in列表
        LinkedList<Integer> in=new LinkedList<Integer>();
        for(int c:nums) in.add(c);
        // 递归
        List<List<Integer>> res=new LinkedList<>();
        recur(new LinkedList<Integer>(),in,res);
        return res;
    }
    private void recur(LinkedList<Integer> tmp,LinkedList<Integer> nums,List<List<Integer>> res){
        if(nums.size()==0){
           res.add(new LinkedList<Integer>(tmp));return;
        }
        int len=nums.size(),last=0;
        for(int i=0;i!=len;i++){
        	// 获得并删除
            last=nums.get(i); nums.remove(i);
            // tmp更新
            tmp.add(last);// update last->add
            // 递归
            recur(tmp,nums,res);
            // tmp删除最后一个
            tmp.removeLast();
            // nums在指定位置插入
            nums.add(i,last);
        }
    }
}
```
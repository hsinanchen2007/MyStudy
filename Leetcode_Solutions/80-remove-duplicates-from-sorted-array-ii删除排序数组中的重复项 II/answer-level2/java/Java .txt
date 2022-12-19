![image.png](https://pic.leetcode-cn.com/25f0db21625d05ba3d78dd33d2bcb587aecfa8cf3fabeac7f7dc8a4fb230de2a-image.png)

```
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length==0) return 0;
        
        int mark = nums[0],mark2 = 0; //mark记录当前数据,mark2记录数据出现的次数
        int index = 1;
        
        for(int i =1 ; i<nums.length ; i++) {
        	if(nums[i]==mark) {  //与记录数据相同,出现次数加一
        		mark2++;
        		if(mark2<2) //出现2次及以下都可以添加
        			nums[index++] = mark;
        	}else { //不相同直接添加并且mark为当前数据
        		mark2=0;
        		mark = nums[i];
        		nums[index++] = mark;
        	}
        }
    	return index;
    }
}
```




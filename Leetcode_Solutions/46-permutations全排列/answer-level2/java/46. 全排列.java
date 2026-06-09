/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/11/13
 * 
 * 解题思路: 排列树
 * 
 */
```
public class leetcode046 {

    List<List<Integer>> lists = new ArrayList<>();

    public void backtrack_PL(int[] nums , int t){

        if(t > nums.length - 1){
            List<Integer> list = new ArrayList<>();
            for(int i = 0;i < nums.length;i++){
                list.add(nums[i]);
            }
            lists.add(list);
        }else{
            for(int i = t;i < nums.length;i++){
                swap(nums,t,i);
                backtrack_PL(nums,t+1);
                swap(nums,t,i);
            }
        }

    }

    public void swap(int[] S , int l , int r){
        int t = S[l];
        S[l] = S[r];
        S[r] = t;
    }

    public List<List<Integer>> permute(int[] nums) {
        backtrack_PL(nums,0);
        return lists;
    }

    public static void main(String[] args) {

        int[] s = new int[]{111,222,333};
        List list = Arrays.asList(s);

        leetcode046 leetcode046 = new leetcode046();
        leetcode046.backtrack_PL(new int[]{1,2,3},0);
    }
}

```
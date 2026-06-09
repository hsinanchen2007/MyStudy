执行用时 :20 ms, 在所有 Java 提交中击败了96.14%的用户
内存消耗 :45.5 MB, 在所有 Java 提交中击败了64.28%的用户

```
1. import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class Solution_29 {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Arrays.sort(nums);
        int index = 0;
        Val_and_Num[] array = new Val_and_Num[nums.length];
        array[index] = new Val_and_Num(nums[0],1);
        for (int i=1; i<nums.length; i++){
            if (nums[i]!=nums[i-1]){
                index++;
                array[index] = new Val_and_Num(nums[i],1);
            }else {
                array[index].num++;
            }
        }

        Arrays.sort(array,0,index+1,new Comparator<Val_and_Num>() {
            @Override
            public int compare(Val_and_Num o1, Val_and_Num o2) {
                return o2.num-o1.num;
            }
        });
        List<Integer> resultList = new ArrayList<>();
        for (int i=0; i< k; i++)
            resultList.add(array[i].val);
        return resultList;
    }

    public static void main(String[] args) {
        new Solution_29().topKFrequent(new int[]{5,2,5,3,5,3,1,1,3},2);
    }
}
class Val_and_Num{
    int val;
    int num;
    public Val_and_Num(){

    }
    public Val_and_Num(int val, int num){
        this.val = val;
        this.num = num;
    }
}
```

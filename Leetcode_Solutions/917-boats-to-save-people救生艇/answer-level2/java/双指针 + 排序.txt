基本思路就是排序，判断最重与最轻的重量之和是否小于等于limit，如果是则可以一起过去，否则重的先过去。

```
class Solution {
    public int numRescueBoats(int[] people, int limit) {
        int count = 0;
        int left = 0, right = people.length - 1;
        Arrays.sort(people);
        while(left <= right){
            ++count;
            if(people[left] + people[right] <= limit) ++left;
            --right;
        }
        return count;
    }
}
```
时间复杂度为`O(nlongn)`，主要用于排序。空间复杂度为`O（1）`。

但因为本题给的`limit`并不大，所以可以优化排序算法。定义数组`arr[limit]`,下标表示个人的体重，arr[i]表示人数。
```
class Solution {
    public int numRescueBoats(int[] people, int limit) {
        int lenth = people.length, num = 0;
        if (lenth == 0)
            return 0;
        int[] arr = new int[limit + 1];
        for (int i = 0; i < lenth; i++) {
        	//people[i]是体重，对应arr数组的下标
            arr[people[i]]++;//统计人数
        }

        int k = 0;
        //排序
        for (int i = 0; i <= limit; i++) {
            while (arr[i] != 0) {
            	//i为体重
                people[k] = i; //重新为people数组排序
                arr[i]--;
                k++;
            }
        }


        int cur = 0;
        for (int i = lenth - 1; i >= cur; i--) {
            if (limit - people[i] >= people[cur]) {
                cur++;
            }
            num++;
        }

        return num;
    }
}
```
时间复杂度为`O(n)`,空间复杂度为`O(n)`。









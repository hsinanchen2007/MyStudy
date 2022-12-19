### 解题思路
我一开始的思路是：先对数组排序，然后找到每个元素对应的rank，之后再生成答案ans（也就是被注释掉的代码）。

上面的思路需要Map来做映射，但是要是可以用数组来实现就更好了。

1. 先找到最大的元素和最小的元素，那么用来对应rank的数组大小就是max - min + 1
2. 将每个元素对应到rank数组，将arr存在的元素位置变为1
3. 最后将arr中的每个元素对应到其的rank值。

### 代码

```java
//本质先计算每个元素对应的rank位置

class Solution {
    public int[] arrayRankTransform(int[] arr){

        int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE, j = 1;

        for(int i : arr){
            if(i > max) max = i;
            if(i < min) min = i;
        }

        int[] bucket = new int[max - min + 1];

        for(int i : arr){
            bucket[i - min] = 1;
        }

        for(int i = 0; i < bucket.length; i++){
            if(bucket[i] != 0){
                bucket[i] = j++;
            }
        }

        int[] ans = new int[arr.length];

        int index = 0;
        for(int i:arr){
            ans[index++] = bucket[i - min];
        }
        return ans;
    }
}


// class Solution {
//     public int[] arrayRankTransform(int[] arr) {

//         //先克隆一个arr
//         int[] temp = arr.clone();
//         //对arr进行排序
//         Arrays.sort(temp);

//         //创建一个map保存元素及对应的排序rank
//         HashMap<Integer, Integer> map = new HashMap<>();

//         int rank = 1;
//         for(int i = 0; i < temp.length; i++){
//             map.put(temp[i], rank);
//             if(i == temp.length - 1) break;
//             rank += (temp[i] != temp[i + 1]) ? 1 : 0;

//         }

//         for(int i = 0; i < arr.length; i++){
//             arr[i] = map.get(arr[i]);
//         }
//         return arr;
//     }
// }
```
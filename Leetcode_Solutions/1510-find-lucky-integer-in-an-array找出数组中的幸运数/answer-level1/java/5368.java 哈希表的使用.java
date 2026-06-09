// ### 解法 使用HashMap

// ```java
public int findLucky(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int i : arr)
            map.put(i, map.getOrDefault(i, 0) + 1);
        int res = -1;
        for(int key : map.keySet()){
            if(key == map.get(key))
                res = Math.max(res, key);
        }
        return res;
    }
// ```

// 思路分析：

// * 由题目对幸运数字的定义，我们需要先统计每一个元素出现的次数，这很显然使用`HashMap`就可以，键为元素，值为该元素出现的次数。统计某个元素的出现次数，如果该元素的值与出现次数相同，他就是一个幸运数字。
// * 对`map`中的键进行遍历。题目要求返回最大的幸运数组，所以当遇到幸运数字时，需要进行更新`res = Math.max(res, key);`
// * 注意，没有幸运数的时候返回-1，所以初始状态的`res = -1`。在循环中没有找到幸运数，将其返回时才不会出现错误。
// * 时间复杂度为$O(n)$，空间复杂度为$O(n)$。

// 更多LeetCode题解请看我的[github](https://github.com/ustcyyw/yyw_algorithm)，地址https://github.com/ustcyyw/yyw_algorithm。还有别的小项目也很好玩~卑微求个小星星💖
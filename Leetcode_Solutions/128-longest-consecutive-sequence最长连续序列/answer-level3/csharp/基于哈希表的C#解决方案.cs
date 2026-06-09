哈希大法好。
- 时间复杂度：O(n)
- 执行用时：156 ms
- 解题思路
  - 构建一个字典Dictionary<int, KeyValuePair<int, int>>（具备哈希表性质），key存储数组（nums）元素，value是一个键值对（ KeyValuePair<int, int>），键值对的key存储当前元素所在连续序列的头（head），value存储当前元素所在连续序列的尾（tail）
  - 遍历数组
    - 如果当前元素（nums[i]）存在于字典中，则不作处理，遍历下一个
    - 如果当前元素不在字典中，则确定其所在区间。
      - 判断当前元素的前值（如果当前元素是5，则前值是4，即 nums[i] - 1）是否在字典中。如果前值存在，则前值对应的 KeyValuePair<int, int>的key就是当前元素所在区间的head；如果前值不存在，则head为当前值
      - 判断当前元素的后值（如果当前元素是5，则后值是6，即 nums[i] + 1）是否在字典中。如果后值存在，则后值对应的 KeyValuePair<int, int>的value就是当前元素所在区间的tail；如果后值不存在，则tail为当前值
      - 更新当前元素所在区间的首尾对应的KeyValuePair至最新
    - 计算当前元素所在区间的长度（tail - head + 1 ），如果大于maxLength，则更新maxLength
    - 将当前元素及其对应的KeyValuePair<int, int>(head, tail))添加到字典中
  - 返回maxLength


```
public class Solution {
    public int LongestConsecutive(int[] nums) {
        var dic = new Dictionary<int, KeyValuePair<int, int>>();
        var maxLength = 0;//最大长度
        var head = 0;
        var tail = 0;
        for (int i = 0; i < nums.Length; i++)
        {
            if (!dic.ContainsKey(nums[i]))
            {
                if (dic.ContainsKey(nums[i] - 1))//前一个数值存在于dic中
                {
                    head = dic[nums[i] - 1].Key;
                }
                else
                {
                    head = nums[i];
                }

                if (dic.ContainsKey(nums[i] + 1))//后一个数值存在于dic中
                {
                    tail = dic[nums[i] + 1].Value;
                }
                else
                {
                    tail = nums[i];
                }

                if (head != nums[i])//如果当前值不是所在区间的头
                {
                    dic[head] = new KeyValuePair<int, int>(head, tail);
                }

                if (tail != nums[i])//如果当前值不是所在区间的尾
                {
                    dic[tail] = new KeyValuePair<int, int>(head, tail);
                }

                if (tail - head + 1 > maxLength)
                {
                    maxLength = tail - head + 1;//更新最大长度
                }

                dic.Add(nums[i], new KeyValuePair<int, int>(head, tail));
            }
        }

        return maxLength;
    }
}
```
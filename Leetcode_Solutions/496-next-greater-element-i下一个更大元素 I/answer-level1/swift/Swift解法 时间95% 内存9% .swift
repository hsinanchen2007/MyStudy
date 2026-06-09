### 解题思路
此处撰写解题思路

1. 变量
    一个map来存nums2中的每一项的右侧第一大值
    一个result用来存放最终的结果
    一个栈用来存暂时未找到右侧第一大值的数字

2. 执行步骤

    遍历nums2的每一项，当前项若是比栈中的最后一项大，则当前项为栈中此项的右侧第一大值,然后将自己入栈。
    遍历结束得到一个map用来存放nums2中有右侧第一大值的全部项。

    遍历nums1,从map中取出key为nums1遍历项的值，若没有给-1！


### 代码

```swift
class Solution {
    func nextGreaterElement(_ nums1: [Int], _ nums2: [Int]) -> [Int] {
        
        var result = [Int]();
        var dict = [Int:Int]();
        var stack = [Int]();

        for num in nums2 {

            //stack有值
            while !stack.isEmpty && stack.last! < num  {
                let last = stack.removeLast();
                dict[last] = num;
            }
            stack.append(num);
        }

        for num in nums1 {
            result.append(dict[num] ?? -1)
        }
        return result
    }
}

```
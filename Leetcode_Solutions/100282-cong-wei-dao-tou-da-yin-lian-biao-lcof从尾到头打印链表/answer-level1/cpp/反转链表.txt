### 运行结果

![image.png](https://pic.leetcode-cn.com/ecb7391adeb2893942668eca5b11352068fe5c489c608669e15e14f4796ed4c9-image.png)

![image.png](https://pic.leetcode-cn.com/91aaf87a09d64e83bac8371fdc3ca6ce0efec97001ef843376848f2d8318d64f-image.png)

![image.png](https://pic.leetcode-cn.com/00604ba9c62fe9421c9991016c9f407b17ae260186ffa372e2f14c60fb9254d2-image.png)

### 解题思路
简单题，遍历链表

### 代码

```C++ []
class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        vector<int> ans;
        while (head != nullptr)
        {
            ans.push_back(head->val);
            head = head->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
```Rust  []
impl Solution {
    pub fn reverse_print(head: Option<Box<ListNode>>) -> Vec<i32> {
        let mut ans:Vec<i32>  = vec![];
        let mut headlist = head;
        while let Some(node) = headlist {
            ans.push(node.val);
            headlist = node.next;
        }
        ans.reverse();
        return ans;
    }
}
```
```Go []
func reversePrint(head *ListNode) []int {
	var ans, tmp []int
	for head != nil {
		tmp = append(tmp, head.Val)
		head = head.Next
	}
	
	for i := (len(tmp) - 1); i >= 0; i-- {
		fmt.Println(i)
		ans = append(ans, tmp[i])
	}

	return ans
}
```

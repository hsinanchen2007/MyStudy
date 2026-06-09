### 解题思路

&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;始终注意：题设给的数据结构是单链表，意味着我们不能像解决数组一样的随意方向移动指针，而是只能从头结点开始依次遍历到尾，同时也意味着我们无法回溯来解决该问题。所以会有两个考虑方向：一，借用辅助数据结构解决问题，本质上就是记录单一指针运动轨迹，将链表元素转换为辅助数据结构存储；二、在不利用多余空间的前提下，考虑双指针来解决问题，比较常见的是快慢指针。
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;先说第一种。容易简单想到：创建一个辅助数组来记录链表元素，然后在辅助数组中，使用对撞指针来判定回文链表。

<br/>


### 代码
```cpp
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head)
            return true;
        if(!head->next)
            return true;
        vector<int> record;   
        ListNode* first = head;
        while(first){
            record.push_back(first->val);
            first = first->next;            
        }
            
        int left = 0, right = record.size() - 1;
        while(left < right){
            if(record[left] != record[right])
                return false;
            left++;
            right--;
        }

        return true;
    }
};
```

<br/>

### 优化思路
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;再说第二种，也就是优化思路。首先我们要明确一点，**遍历只能从头到尾**，其实就说明只思考双指针的变化显然无法解决问题，更何况变化不是很多，即使我们清楚要使用快慢指针，但快慢的程度我们还是不清楚。这时一定要**观察回文链表的特点**，像初中几何里作辅助线一样，利用回文链表的特点辅助双指针解题。那么回文链表什么特点？前后部分相等。**理想化的思路**是存在那么两个指针在链表中间处向两边遍历来判断回文，但是这是单链表不能回溯。那么我们让左半部分变得可以"回溯"呢？如果熟悉链表操作的朋友可能知道**反转链表**。如果将前半部分反转过来，那么从中间向两头遍历将成为可能！
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;问题的解决方案找到了，现在就要实现反转前半部分的链表了，那么计算机怎么知道哪里是前半部分？当然是通过快慢指针。**快两步慢一步**，如此反复，当快指针走到头时，慢指针恰好处于中间处（奇偶链表位置略有不同，不过无碍）。而在慢指针移动过程中，我们就不断将前半部分反转形成前半部分的反转链表。剩下的就是向两端遍历判断回文了。
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;**建议**：对于遍历反转过程和奇偶链表的指针位置不同，最好自己找个简单例子过一遍，自然清晰。本文只是将我的思考过程展现罢了，仅供参考～
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;此外，也可以反转后半部分，可自行尝试～


<br/>

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head)
            return true;
        if(!head->next)
            return true;
        
        ListNode* fast = head;  //fast一次走两步，slow一次走一步
        ListNode* slow = head;
        ListNode* pre = NULL;    //作用：反转链表充当slow的前驱指针

        //反转前半部分，slow和pre作为判断回文链表的双指针
        while(fast && fast->next){    //奇数链：slow位于链表中点，pre位于待判断的前半部分的第一位
                                      //偶数链：slow位于待判断的后半部分的第一位，pre位于待判断的前半部分的第一位
            fast = fast->next->next;

            ListNode *nex = slow->next;
            //反转
            slow->next = pre;
            //更新
            pre = slow;
            slow = nex;
        }

        if(fast) //判断奇数链
            slow = slow->next;   //slow移动到待判断的后半部分的第一位
        
        //判断回文
        while(slow && pre){
            if(slow->val != pre->val)
                return false;
            slow = slow->next;
            pre = pre->next;
        }

        return true;
    }
};
```

<br/>


>如果有错误或者不严谨的地方，请务必给予指正，十分感谢。
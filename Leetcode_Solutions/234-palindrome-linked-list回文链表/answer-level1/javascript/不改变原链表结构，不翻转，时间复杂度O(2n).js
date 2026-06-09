这个方法可能有点奇葩=L=

思路：
1. 遍历拿到长度
2. 通过递归从最后一个节点开始比较，同时用一个指针从头部依次向后挪，一共比较 长度/2次

```
var isPalindrome = function(head) {
    if(!head||!head.next){
        return true;
    }
    let slow = head;
    let cur = head;
    
    let len = 1;
    while(cur.next){
        ++len;
        cur = cur.next;
    }
    
    let count = 0;
    function isPalindromeLastPart(node){
        const nextNodeIsPalindrome = node.next?isPalindromeLastPart(node.next):false;
        if(!node.next || nextNodeIsPalindrome){
            if(count>=len/2){
                return nextNodeIsPalindrome
            }else{
                const result = slow.val === node.val;
                ++count;
                slow = slow.next;
                return result;
            }
        }else{
            return false;
        }
    }
    
    return isPalindromeLastPart(head)

};
```

都怪我基础不扎实=L= 这个空间复杂度应该不算O(1)吧，白高兴了
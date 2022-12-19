- key1: 合并两个有序链表的时候不必使用嵌套while使得时间复杂度变成O(mn)，直接``l1&&l2``即可
- key2: 空间复杂度为O(1)
```javascript
    /**
     * 时间复杂度：O(NlogK) 其中k是链表的数目
     */
    const mergeKLists =lists=>{
        if(lists.length<1) return null;
        const mergeTwoLists=(l1,l2)=>{
            let res=new ListNode(),ans=res;
            while(l1&&l2){
                if(l1.val>l2.val){
                    ans.next=l2;
                    l2=l2.next;
                }else{
                    ans.next=l1;
                    l1=l1.next;
                }
                ans=ans.next;
            }
            let rest=l1||l2;
            ans.next=rest;
            return res.next;
        };
        const helper=(arr)=>{
            if(arr.length===1) return arr[0];
            if(arr.length===2){
                return mergeTwoLists(arr[0],arr[1]);
            }
            let mid=Math.floor(arr.length/2);
            let left=helper(arr.slice(0,mid));
            let right=helper(arr.slice(mid));
            return mergeTwoLists(left,right);
        };
        return helper(lists);
    };
```

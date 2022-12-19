可以问下js使用双指针时是怎么判断快慢指针重叠的，因为js中next指针是对象，判断2个对象相等？？？
var hasCycle = function(head) {
    //法1
    // let cur = head
    // //每次走过，放在set中
    // //每次快慢指针
    // let set = new Set()
    // while(cur){
    //     if(set.has(cur)){
    //         return true
    //     }else{
    //         set.add(cur)
    //     }
    //     cur = cur.next
    // }
    // return false
    //法2
    let slow = head,fast = head
    while(slow && fast && fast.next){
        slow = slow.next
        fast = fast.next.next
        if(slow ===fast){
            return true
        }
    }
    return false
};
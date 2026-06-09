 溢出校验写的不美 

![WechatIMG1.jpeg](https://pic.leetcode-cn.com/188454120eabbf27c6e9d49d613a7145cb8f5f1457a5938149ca89f3eadf4dca-WechatIMG1.jpeg)

func swapPairs(head *ListNode) *ListNode {   
    
    var a1 *ListNode
    var a2 *ListNode
    a4 := head

    for head!=nil{
        
            a1 = head.Next
            if a1 == nil {return a4}
            a2 = head.Next.Next

            if a4 == head{

                head.Next = a2
                a1.Next = head
                a4 = a1
                
            }else{
                
                if a2 == nil{return a4}
                head.Next = a2
                a1.Next = a2.Next
                a2.Next = a1
                head = head.Next.Next
            }
    }
    return a4
}
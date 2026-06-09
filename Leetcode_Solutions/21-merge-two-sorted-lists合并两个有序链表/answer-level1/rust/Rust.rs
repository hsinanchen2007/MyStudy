通过一个create_list函数和sort操作简化了操作逻辑。写这题的主要不目的就是熟悉OPTION和BOX的搭配操作，最后虽然通过了，但是好像逃避了最初遇见的一些问题。rust做法如下：
```
fn show(l1:Option<Box<ListNode>> )  {
    let mut l1_in = l1.unwrap();
    while l1_in.next!=None {
        println!("{:?}", l1_in.val);
        let l1 = l1_in.next;
        l1_in=l1.unwrap();
    }
    println!("{:?}", l1_in.val);

}
fn mycmp(a:&i32,b:&i32) -> Ordering {
    if a <b {
        return Ordering::Greater;
    }else if a==b{
        return Ordering::Equal;
    }else{
        return Ordering::Less;
    }
}
pub fn merge_two_lists(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let  l1 = l1;
        let  l2 = l2;
        if l1==None {
            return l2;
        }else if l2==None {
            return l1;
        }else{
            let mut res = vec![];
            let mut l1_in = l1.unwrap();
            let mut l2_in = l2.unwrap();
            while l1_in.next!=None{
                res.push(l1_in.val);
                let l1 = l1_in.next;
                l1_in=l1.unwrap();
            }
            res.push(l1_in.val);
            while l2_in.next!=None{
                res.push(l2_in.val);
                let l2 = l2_in.next;
                l2_in=l2.unwrap();
            }
            res.push(l2_in.val);

            res.sort_by(mycmp);
           
            return create_list(res);
        }

}
fn create_list(arg: Vec<i32>) -> Option<Box<ListNode>> {
    if arg.len()==0 {
        return None;
    }else{
        let mut res_2 = ListNode::new(0);
        let mut flag = 0;
        for i in arg {
            let mut res = ListNode::new(i);
            if flag==1 {
                res.next = Some(Box::new(res_2));    
            }else{
                flag=1;
            }
            res_2 = res;
        }
        return Some(Box::new(res_2));
    }
}
fn main() {

    let b = merge_two_lists(create_list(vec![1,2,4]),create_list(vec![1,3,4]));
    show(b);

}
```

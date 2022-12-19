12ms，原理参考其它题解，额外难点在所有权系统。

```
impl Solution {
    pub fn sort_list(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.is_none() {
            return None;
        }
        let mut len = 1;
        loop {
            let mut new_head = None;
            let mut new_tail = None;
            let mut loop_count = 0;
            loop {
                loop_count += 1;
                let mut take_head = None;
                let mut take_tail = None;
                for _ in 0..len {
                    if let Some(mut t) = head {
                        head = t.next.take();
                        if take_tail.is_none() {
                            take_head = Some(t);
                            take_tail = take_head.as_mut();
                        } else {
                            take_tail = take_tail.map(|p| {
                                p.next = Some(t);
                                p.next.as_mut().unwrap()
                            });
                        }
                    } else {
                        break;
                    }
                }
                let mut count = len;
                loop {
                    let mut pick = None;
                    if take_head.is_some() && head.is_some() && count > 0 {
                        if take_head.as_ref().unwrap().val <= head.as_ref().unwrap().val {
                            pick = take_head;
                            take_head = pick.as_mut().unwrap().next.take();
                        } else {
                            count -= 1;
                            pick = head;
                            head = pick.as_mut().unwrap().next.take();
                        }
                    } else if take_head.is_some() {
                        pick = take_head;
                        take_head = pick.as_mut().unwrap().next.take();
                    } else if head.is_some() && count > 0 {
                        count -= 1;
                        pick = head;
                        head = pick.as_mut().unwrap().next.take();
                    }
                    if pick.is_none() {
                        break;
                    }
                    if new_tail.is_none() {
                        new_head = pick;
                        new_tail = new_head.as_mut();
                    } else {
                        new_tail = new_tail.map(|p| {
                            p.next = pick;
                            p.next.as_mut().unwrap()
                        });
                    }
                }
                if count > 0 {
                    break;
                }
            }
            head = new_head;
            len = len * 2;
            if loop_count <= 1 {
                break;
            }
        }
        head
    }
}
```

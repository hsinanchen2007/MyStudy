```
impl Solution {
    pub fn sort_list(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.as_ref() == None {
            return head;
        }

        let mut inv = 1;
        let mut p = &mut head as *mut Option<Box<ListNode>>;
        
        loop {
            unsafe {
                let move_ptr = |mut x: *mut Option<Box<ListNode>>, n: i32| {
                    for _ in 0..n {
                        if (*x) == None {
                            return x;
                        }
                        x = &mut (*x).as_mut().unwrap().next as *mut Option<Box<ListNode>>;
                    }
                    x
                };
                let mut count = 0;

                while (*p).as_ref() != None {
                    let mut l1 = p;
                    let mut l2 = &mut (*move_ptr(p, inv)).take() as *mut Option<Box<ListNode>>;
                    let mut end = (*move_ptr(l2, inv)).take();
                    
                    (*p) = Self::merge_two_lists(l1, l2);
                    p = move_ptr(p, inv*2);
                    (*p) = end;

                    count += 1;
                }
                if count == 1 {
                    break;
                }
            }
            p = &mut head as *mut Option<Box<ListNode>>;
            inv *= 2;
        }
        
        head
    }

   pub fn merge_two_lists(l1: *mut Option<Box<ListNode>>, l2: *mut Option<Box<ListNode>>) -> Option<Box<ListNode>> {        
        let mut head = Some(Box::new(ListNode::new(0)));
        let (mut p1, mut p2, mut pr) = (l1, l2, &mut head as *mut Option<Box<ListNode>>);
        let (mut l1, mut l2) = (None, None);

        unsafe {
            let node_val = |x: *mut Option<Box<ListNode>>| {
                if (*x) == None {
                    None
                }else {
                    Some((*x).as_ref().unwrap().val)
                }
            };

            let node_next = |x: *mut Option<Box<ListNode>>| {
                if (*x) == None {
                    x
                }else {
                    &mut (*x).as_mut().unwrap().next as *mut Option<Box<ListNode>>
                }
            };

            loop {
                match (node_val(p1), node_val(p2)) {
                    (Some(v1), Some(v2)) => {
                       if v1 < v2 {
                            if (*node_next(pr)) != None && node_next(pr) == p2 {
                                l2 = (*node_next(pr)).take();
                                p2 = &mut l2 as *mut Option<Box<ListNode>>;                                
                            }         
                            (*node_next(pr)) = (*p1).take();
                            pr = node_next(pr);
                            p1 = node_next(pr);
                        }else {
                            if (*node_next(pr)) != None && node_next(pr) == p1 {
                                l1 = (*node_next(pr)).take();
                                p1 = &mut l1 as *mut Option<Box<ListNode>>;                                
                            }
                            (*node_next(pr)) = (*p2).take();
                            pr = node_next(pr);
                            p2 = node_next(pr);
                        };
                    },
                    (Some(_), None) => {
                        (*pr).as_mut().unwrap().next = (*p1).take();
                        break;
                    },
                    (None, Some(_)) => {
                        (*pr).as_mut().unwrap().next = (*p2).take();
                        break;
                    },
                    (None, None) => {
                        return None;
                    },
                }
            }
        }

        head.unwrap().next
    }
}
```
![image.png](https://pic.leetcode-cn.com/00c3f5f8a519913a2334df31edc3b861451d326f8a732dd2601152082026970c-image.png)

写完之后发现可能不用unsafe也可以？


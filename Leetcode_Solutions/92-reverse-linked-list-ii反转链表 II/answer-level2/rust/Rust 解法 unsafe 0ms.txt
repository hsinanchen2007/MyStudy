```
type Link = Option<Box<ListNode>>;

impl Solution {
    pub fn reverse_between(head: Link, m: i32, n: i32) -> Link {
        let mut t = Some(Box::new(ListNode::new(-1)));
        t.as_mut().unwrap().next = head;
        let mut head = t;

        let (mut left, mut right) = (&mut head as *mut Link, &mut head as *mut Link);

        unsafe {
            let move_p = |mut x: *mut Link, n: i32| {
                for _ in 0..n {
                    if *x == None {
                        return x;
                    }
                    x = &mut (*x).as_mut().unwrap().next as *mut Link;
                }
                x
            };

            left = move_p(left, m-1);
            right = move_p(left, 1);

            if *right == None || m==n {
                return head.unwrap().next;
            }

            let mut rev: Link = None;
            let mut rev_p = &mut None as *mut Link;
            let mut first = rev_p;
            let mut right_list: Link = None;

            for i in 0..(n-m+1) {
                let right_next = (*move_p(right, 1)).take();
                let mut t = (*right).take();
                t.as_mut().unwrap().next = (*rev_p).take();
                rev = t;
                rev_p = &mut rev as *mut Link;
                if i == 1 {
                    first = move_p(rev_p, 1);
                }
                right_list = right_next;
                right = &mut right_list as *mut Link;
            }

            (*left).as_mut().unwrap().next = (*rev_p).take();
            (*first).as_mut().unwrap().next = (*right).take();
        }

        head.unwrap().next
    }
}
```
![image.png](https://pic.leetcode-cn.com/e84f8a6cafc591777d35f191cc0dcbf77ddad3b7d22953dce389854bb48da3fe-image.png)

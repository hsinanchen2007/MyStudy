```

var nextLargerNodes = function(head) {
        let p = head,
            res = [];
        while (p) {
            let q = p.next,
                flag = true;
            while (q) {
                if (q.val > p.val) {
                    flag = false;
                    res.push(q.val);
                    break;
                } else
                    q = q.next;
            }
            if (flag)
                res.push(0);
            p = p.next;
        } 
        return res;
    
};
```

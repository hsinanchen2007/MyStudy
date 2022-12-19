```
    var splitListToParts = function(head, k) {
        let len = 0,
            res = [],
            p = head;
        while (p) {
            len++;
            p = p.next;
        }
        if (len <= k) {
            let newh = head;
            let newlen = 0;
            while (newh && newh.next) {
                let news = newh.next;
                newh.next = null;
                res.push(newh);
                newh = news;
                newlen++;
            }
            res.push(newh);
            newlen++;
            while (newlen < k) {
                res.push(null);
                newlen++;
            }
            return res;
        }

        let size = ~~(len / k),
            mod = len % k;
        let h = head;
        let i = 1,
            start, end;
        while (h) {
            if (i == 1)
                start = h;
            while (i < size) {
                i++;
                h = h.next;
            }
            if (mod > 0) {
                h = h.next;
                mod--;
            }
            if (!h.next) {
                res.push(start)
                break;
            }
            let end = h.next;
            h.next = null;
            res.push(start);
            h = end;
            i = 1;
        }
        return res;
    };
```

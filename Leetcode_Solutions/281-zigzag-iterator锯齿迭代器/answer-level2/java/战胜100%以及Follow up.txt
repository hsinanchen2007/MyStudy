3ms beat 100%

```
public class ZigzagIterator {
    List<Integer> l1;
    List<Integer> l2;
    int           i, j;
    public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
        l1 = v1;
        l2 = v2;
        i = 0;
        j = 0;
    }

    public int next() {
        if (!hasNext()) return -1;
        if (i<=j) {
            if (i<l1.size())
                return l1.get(i++);
            else{
                if (j<l2.size())
                    return l2.get(j++);
            }
        } else {
            if (j<l2.size())
                return l2.get(j++);
            else{
                if (i<l1.size())
                    return l1.get(i++);
            }
        }

        return -1;
    }

    public boolean hasNext() {
        return i < l1.size() || j < l2.size();
    }
}
```




Follow up: 2ms beat 100%.

```
public class ZigzagIterator {
    List<Integer>[] list;
    int    num = 0;
    int    x   = 0;
    int    y   = 0;

    int count = 0;
    public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
        list = new List[2];
        list[0] = v1;
        list[1] = v2;

        num = list.length;

        for(List<Integer> l : list){
            count+=l.size();
        }
    }

    public int next() {
        int res = -1;
        while (res ==-1 && hasNext()){
            if (x >= list[y].size()){
                if (y + 1 == num){
                    x++;
                }
                y = (y + 1) % num;
            } else{
                res = list[y].get(x);
                if (y + 1 == num){
                    x++;
                }
                y = (y + 1) % num;
            }
        }

        if (res!=-1) count--;
        return res;
    }

    public boolean hasNext() {
        return count > 0;
    }
}



```

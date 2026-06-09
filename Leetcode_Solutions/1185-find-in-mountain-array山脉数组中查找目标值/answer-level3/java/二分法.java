&emsp;&emsp;这题的思路就是先二分法找最高的山，然后再用二分法向两边找。<br>
&emsp;&emsp;不过要注意一下，两种二分法的方式有一点不同。<br>
&emsp;&emsp;另外，有点难受的是，javascript怎么都通不过，所以才改成了Java写了。

```java
class Solution {
    public int findH(MountainArray mountainArr) {
        int s = 0, e = mountainArr.length() - 1;
        while(s < e) {
            int mid = (s + e) / 2,
                v1 = mountainArr.get(mid - 1),
                v2 = mountainArr.get(mid),
                v3 = mountainArr.get(mid + 1);
            if (v2 >= v1 && v2 >= v3) return mid;
            if (v3 > v2) {
                s = mid;
            } else {
                e = mid;
            }
        }
        return -1;
    }
    
    public int find(MountainArray mountainArr, int s, int e, int target, boolean sign) {
        while(s <= e) {
            int mid = (s + e) / 2 | 0,
                v = mountainArr.get(mid);
            if(v == target) return mid;
            if(v > target) {
                s = sign? s: mid + 1;
                e = sign? mid - 1: e;
            } else {
                s = sign? mid + 1: s;
                e = sign? e: mid - 1;
            }
        }
        return -1;
    }
    
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int hk = findH(mountainArr), len = mountainArr.length();
        if(mountainArr.get(hk) == target) return hk;
        int f1 = find(mountainArr, 0, hk - 1, target, true);
        if (f1 >= 0 && mountainArr.get(f1) == target) return f1;
        int f2 = find(mountainArr, hk + 1, len - 1, target, false);
        if (f2 >= 0 && mountainArr.get(f2) == target) return f2;
        return -1;
    }
}
```
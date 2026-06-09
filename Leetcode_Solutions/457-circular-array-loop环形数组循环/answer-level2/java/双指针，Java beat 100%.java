时间复杂度为O(n)，空间复杂度为O(1)
思路是：
    对于查找数组或链表中有没有环的问题，多可以朝快慢指针的方向去想，本题也不例外。基本思想是快慢指针。还有一些小细节和技巧的东西需要考虑在内。
    1）数组长度为0时，认为无环。
    2）快慢指针的思想是慢指针走一步，快指针走两步，若他俩相遇肯定是在环中的某一个节点上相遇，则证明存在环。
    3）假设位置i的元素是环中的一点，通过快慢指针的思想，假定慢指针为j快指针为k，那么一定会有j==k的时候。问题是位置i可能不是环中的一个节点。鉴于此肯定是要遍历全部的节点的。for(i = 0; i < nums.length;++i>)对于这样的i都要试一试是否是环中的一个节点，若是则return true，否则则return false；如果这样的话，肯定做不到时间复杂度是O(n)的程度，要稍微“剪下枝”。
    4）根据提示，nums中所有元素都不可能是0。这是剪枝可以进行的关键。另一个原则是如果存在环，那么环中的所有数字的符号都必须是一致，否则不满足题意。这时我们认为本链条不处于环上。然后将节点i到当前位置的所有元素置0，以标记这些节点都不在环上。
    5）另一点是：当某节点j指向已经确定不在环中的节点时，就不必继续走下去了，节点j肯定也不在环上。
    6）当循环长度为1是，也是不存在环的，比如[8,2]这个数组，从任意位置开始都指向它自己。我们认为他是无环的。
    基本思路说完了，不知道读者懂没懂^_^。
    重述下无环的判定依据：
    1）当快慢指针指向的新节点发现和上一个节点符号不一致。
    2）当快慢指针指向的位置不变时。
    3）快慢指针指向了不可能是环中节点的节点(该节点位置已经置0的节点)时。
```
private void setZero(int[] nums, int i){
        int j;
        while (true) { // !(nums[j] == 0 || nums[i]*nums[j]<0)
            j = (i + nums[i] + 5000*nums.length) % nums.length;
            if (nums[j] == 0 || nums[i]*nums[j]<0) {
                nums[i] = 0;
                break;
            }
            nums[i] = 0;
            i = j;
        }
    }

    // beat 100%
    public boolean circularArrayLoop(int[] nums) {
        if (nums.length == 0) return false;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) continue;
            int lastJ, lastK;
            int j=i, k=i;

            while (true) {
                lastJ = j;
                j = (j + nums[j] + 5000*nums.length) % nums.length;
                if (nums[lastJ]*nums[j] < 0 || nums[j] == 0 || lastJ == j) {
                    setZero(nums, i);
                    break;
                }
                lastK = k;
                k = (k + nums[k] + 5000*nums.length) % nums.length;
                if (nums[lastK]*nums[k] < 0 || nums[k] == 0 || lastK == k){
                    setZero(nums, i);
                    break;
                }
                lastK = k;
                k = (k + nums[k] + 5000*nums.length) % nums.length;
                if (nums[lastK]*nums[k] < 0 || nums[k] == 0 || lastK == k){
                    setZero(nums, i);
                    break;
                }
                if (j == k)
                    return true;
            }
        }
        return false;
    }
```
如果对您有帮助给个赞吧^_^
其实这题就是考的滑动窗口的概念，在TCP、限流、熔断的方案中，滑动窗口是个基本概念。

我的解法就是维护一个双向队列，该双向队列中维护了3000ms以内的时间。

一旦有新的ping请求进来，就根据ping的时间不断的从队列中取出时间差超过3000ms的元素，最后将当前ping请求的时间加到队列中即可。

```
private Deque<Integer> queue = new ArrayDeque<>();
​
    public int ping(int t) {
        while (!queue.isEmpty()) {
            Integer tt = queue.removeFirst();
            if (t - 3000 <= tt) {
                queue.addFirst(tt);
                break;
            }
        }
        queue.add(t);
        return queue.size();
    }

```

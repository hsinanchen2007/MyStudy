### 解题思路
偶数编号的哲学家如果要就餐，则规定先拿起左叉，再拿起右叉
奇数编号的哲学家如果要就餐，规定先拿起右叉，再拿起左叉

right_fork = philosopher
left_fork = (philosopher+1)%5

假设0号哲学家 和 1号哲学家准备同时就餐
0号拿起 左叉 1号叉
1号准备拿起 右叉 也就是1号叉的时候，发现1号叉已经被0号哲学家争先使用，
则需等待0号哲学家就餐结束后，释放出1号叉，才能拿起2号叉 进行就餐

### 代码

```python
import threading

rlock_list = [threading.RLock()]*5

class DiningPhilosophers(object):

    # call the functions directly to execute, for example, eat()
    def wantsToEat(self, philosopher, pickLeftFork, pickRightFork, eat, putLeftFork, putRightFork):
        """
        :type philosopher: int
        :type pickLeftFork: method
        :type pickRightFork: method
        :type eat: method
        :type putLeftFork: method
        :type putRightFork: method
        :rtype: void
        """
        right_fork = philosopher
        left_fork = (philosopher+1)%5
        if philosopher==0: ## 偶数
            rlock_list[left_fork].acquire()
            pickLeftFork()
            rlock_list[right_fork].acquire()
            pickRightFork()
            
            eat()

            putLeftFork()
            rlock_list[left_fork].release()
            putRightFork()
            rlock_list[right_fork].release()
        else:
            rlock_list[right_fork].acquire()
            pickRightFork()
            rlock_list[left_fork].acquire()
            pickLeftFork()
            
            eat()

            putLeftFork()
            rlock_list[left_fork].release()
            putRightFork()
            rlock_list[right_fork].release()

```
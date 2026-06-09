#### 方法一：维护有序的座位编号

我们可以用有序集合（`Java` 中 `TreeSet`，`C++` 中的 `set`）存储目前有学生的座位编号。当我们要调用 `leave(p)` 函数时，我们只需要把有序集合中的 `p` 移除即可。当我们要调用 `seat()` 函数时，我们遍历这个有序集合，对于相邻的两个座位 `i` 和 `j`，如果选择在这两个座位之间入座，那么最近的距离 `d` 为 `(j - i) / 2`，选择的座位为 `i + d`。除此之外，我们还需要考虑坐在最左侧 `0` 和最右侧 `N - 1` 的情况。

```Java [sol1]
class ExamRoom {
    int N;
    TreeSet<Integer> students;

    public ExamRoom(int N) {
        this.N = N;
        students = new TreeSet();
    }

    public int seat() {
        //Let's determine student, the position of the next
        //student to sit down.
        int student = 0;
        if (students.size() > 0) {
            //Tenatively, dist is the distance to the closest student,
            //which is achieved by sitting in the position 'student'.
            //We start by considering the left-most seat.
            int dist = students.first();
            Integer prev = null;
            for (Integer s: students) {
                if (prev != null) {
                    //For each pair of adjacent students in positions (prev, s),
                    //d is the distance to the closest student;
                    //achieved at position prev + d.
                    int d = (s - prev) / 2;
                    if (d > dist) {
                        dist = d;
                        student = prev + d;
                    }
                }
                prev = s;
            }

            //Considering the right-most seat.
            if (N - 1 - students.last() > dist)
                student = N - 1;
        }

        //Add the student to our sorted TreeSet of positions.
        students.add(student);
        return student;
    }

    public void leave(int p) {
        students.remove(p);
    }
}
```

```Python [sol1]
class ExamRoom(object):
    def __init__(self, N):
        self.N = N
        self.students = []

    def seat(self):
        # Let's determine student, the position of the next
        # student to sit down.
        if not self.students:
            student = 0
        else:
            # Tenatively, dist is the distance to the closest student,
            # which is achieved by sitting in the position 'student'.
            # We start by considering the left-most seat.
            dist, student = self.students[0], 0
            for i, s in enumerate(self.students):
                if i:
                    prev = self.students[i-1]
                    # For each pair of adjacent students in positions (prev, s),
                    # d is the distance to the closest student;
                    # achieved at position prev + d.
                    d = (s - prev) / 2
                    if d > dist:
                        dist, student = d, prev + d

            # Considering the right-most seat.
            d = self.N - 1 - self.students[-1]
            if d > dist:
                student = self.N - 1

        # Add the student to our sorted list of positions.
        bisect.insort(self.students, student)
        return student

    def leave(self, p):
        self.students.remove(p)
```

**复杂度分析**

* 时间复杂度：`seat()` 函数的时间复杂度为 $O(P)$，其中 $P$ 是当前入座学生的数目。每次调用 `seat()` 函数我们都需要遍历整个有序集合。`leave()` 函数的时间复杂度为 $O(P)$（`Python` 代码中）或者 $O(\log P)$（`Java` 代码中）。

* 空间复杂度：$O(P)$，用于存储有序集合。
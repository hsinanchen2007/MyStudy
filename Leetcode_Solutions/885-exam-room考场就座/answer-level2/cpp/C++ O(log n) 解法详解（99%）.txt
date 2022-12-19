为实现 `O(log n)` 级别的算法，考虑两个操作：
+ `seat()` 需要取出当前最优的一个区间，使得在该区间内插入学生后距离最优。
+ `leave(p)` 需要按照位置取出两个相邻区间并将其合并。

定义区间：
```c++
static const i32 RIGHT_BOUND = std::pow(10, 9) + 100;
static const i32 LEFT_BOUND = -1;

// section [left, right] where left and right are taken
struct Section {
    i32 left;
    i32 right;
    Section(int l, int r) : left(l), right(r) {}
    Section() : left(LEFT_BOUND), right(RIGHT_BOUND) {}
};
```

### `seat` 操作

很容易根据区间计算出它的一个价值，定义为“在该区间内插入学生后于周围的距离”。
根据这个价值就可以对这些区间维护一个 `O(log n)` 时间内取出最大值的数据结构。
取出区间后，按照最优分割分割成两个区间，再插入，同样要在 `O(log n)` 时间内完成。
这时就可以考虑二叉树或是堆。

操作为：
1. `O(log n)` 选取最大价值的区间，计算出其中的插入位置
2. 从数据结构中删除该区间，并插入两个新区间 `O(log n)`。

### `leave` 操作

需要根据位置查找到保存区间的数据结构的两个相邻区间，并合并为一个。
合并后插入已经保证了 `O(log n)` 复杂度，因此考虑在 `O(log n)` 以内查找并删除相邻区间就可以了。

如果使用一个数据结构来保存位置的左右邻居，那么就可以根据区间的价值来在区间数据结构中进行 `O(log n)` 的查找。
对于二叉树，该查找操作是 `O(log n)`，最坏（全部区间等长）是 `O(n)`（后面会优化）。

考虑使用哈希表来储存点的左右邻居，因为我们不需要任何对位置的排序比较。这样 `leave` 操作可以通过
1.  `O(1)` 查找到左右邻居，
2. 根据左右邻居 `O(log n)` 查找并删除区间
3. 合并区间后以 `O(log n)` 插入合并后的区间
4. 并以 `O(1)` 维护左右邻居。

容易发现 `seat` 操作复杂度不会被影响。

### 等长价值的优化

注意到我们在这里只按照了价值排序，而选取 `seat` 的时候，需要在价值相同时考虑最小位置。
因此把排序的 key 增长到 64 位：
`key = (value << 32) + (0xffffffff - candidate)`
这里 `candidate` 是该区间内选择的位置。需要取负号保证按照 key 排序降序时最小。

这样，我们就可以保证全部操作的最坏复杂度不超过 `O(log n)`。


### 代码
```c++
using i32 = std::int32_t;
using i64 = std::int64_t;
using u64 = std::uint64_t;

static const i32 RIGHT_BOUND = std::pow(10, 9) + 100;
static const i32 LEFT_BOUND = -1;

// section [left, right] where left and right are taken
struct Section {
    i32 left;
    i32 right;
    Section(int l, int r) : left(l), right(r) {}
    Section() : left(LEFT_BOUND), right(RIGHT_BOUND) {}
};

std::ostream& operator<<(std::ostream& is, const Section s) {
    is << "[" << s.left << ", " << s.right << "]";
    return is;
}

class ExamRoom {
    i32 N;
    std::map<i64, Section> id_to_section;
    std::unordered_map<i32, Section> pos_to_boundary;

    // middle of the section (where to insert)
    i32 section_candidate(const Section& section) const {
        if (section.left == LEFT_BOUND) {  // left is empty, select pos 0
            return 0;
        } else if (section.right == RIGHT_BOUND) {  // right empty
            return N - 1;
        } else {  // normal
            return section.left + (section.right - section.left) / 2;
        }
    }

    // space between candidate and nearest student (with offset)
    i32 section_value(const Section& section) const {
        // offset is used to keep value >= 0
        static const constexpr i32 OFFSET = 2;
        i32 value;
        if (section.left == LEFT_BOUND) {  // left is empty
            // for [-INF, 1], sit at 0, value 0
            value = OFFSET + section.right - 1;
        } else if (section.right == RIGHT_BOUND) {
            // for [N-2, INF], value is 0 (sit at N-1)
            value = OFFSET + N - 2 - (section.left);
        } else {
            i32 length = section.right - section.left - 1;  // space length
            // 2N => N-1,  2N+1 => N
            if (length <= 0)
                value = OFFSET - 1;
            else
                value = OFFSET + (length - 1) / 2;
        }
        return value;
    }

    // id of the section, sorting by id is sorting by value and candidate
    // position
    i64 id_of_section(const Section& section) const {
        u64 value = section_value(section);
        i64 candidate = section_candidate(section);
        // sort by value then candidate (reversed)
        return (value << 32) + (0xffffffff - candidate);
    }

   public:
    ExamRoom(int N) : N(N) {
        // mark as empty (-INF and INF as empty boundary)
        Section empty_section = Section(LEFT_BOUND, RIGHT_BOUND);
        id_to_section[id_of_section(empty_section)] = empty_section;

        // never mind, not going to use.
        pos_to_boundary[LEFT_BOUND] = Section(LEFT_BOUND, RIGHT_BOUND);
        pos_to_boundary[RIGHT_BOUND] = Section(LEFT_BOUND, RIGHT_BOUND);
    }

    int seat() {
        // select longest section
        auto iter = id_to_section.rbegin();    // sorted by id
        const Section section = iter->second;  // retrive section

        // get new pos
        i32 pos = section_candidate(section);

        // make new sections and remove old one
        id_to_section.erase(id_of_section(section));  // erase the section
        Section left = Section(section.left, pos);    // make new
        Section right = Section(pos, section.right);
        id_to_section[id_of_section(left)] = left;  // insert to map (tree)
        id_to_section[id_of_section(right)] = right;

        // mark point to section
        pos_to_boundary[pos] = section;             // mark pos' left and right
        pos_to_boundary[section.left].right = pos;  // left boundary changed
        pos_to_boundary[section.right].left = pos;  // right changed

        return pos;
    }

    void leave(int p) {
        Section boundary = pos_to_boundary[p];
        //
        Section left = Section(boundary.left, p);
        Section right = Section(p, boundary.right);

        // merge left and right sections
        id_to_section.erase(id_of_section(left));
        id_to_section.erase(id_of_section(right));
        id_to_section[id_of_section(boundary)] = boundary;

        // mark point to section
        pos_to_boundary.erase(p);  // remove p
        pos_to_boundary[boundary.left].right = boundary.right;
        pos_to_boundary[boundary.right].left = boundary.left;
    }
};
```
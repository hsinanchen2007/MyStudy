```

class NumArray {
    var nums:[Int]!
    var tree:[Int]!
    
    
    init(_ anums: [Int]) {
        nums = anums
        tree = Array<Int>(repeating: 0, count: (anums.count<<1)<<1)
        var numIndex = 0
        build(0, nums.count-1, 0, &numIndex)
    }
    
    func build(_ l:Int, _ r:Int, _ tIndex:Int,_ nIndex:inout Int) {
        if l > r {
            return
        }
        if l == r {
            tree[tIndex] = nums[nIndex]
            nIndex = nIndex+1
            return
        }
        let lChild = tIndex << 1 + 1
        let rChild = tIndex << 1 + 2
        let middle = (l+r) >> 1
        build(l, middle, lChild, &nIndex)
        build(middle+1, r, rChild, &nIndex)
        pushUp(lChild,rChild,tIndex)
    }
    
    func pushUp(_ lChild:Int, _ rChild:Int, _ pIndex:Int) {
        tree[pIndex] = tree[lChild]+tree[rChild]
    }
    
    func update(_ i: Int, _ val: Int) {
        nums[i] = val
        u(i, val, 0, nums.count-1, 0)
    }
    func u(_ nIndex:Int, _ nValue:Int, _ tL:Int, _ tR:Int, _ tIndex:Int) {
        if tL == tR {
            tree[tIndex] = nValue
            return
        }
        let middle = (tL + tR) >> 1
        if nIndex >= tL && nIndex <= middle {
            u(nIndex, nValue, tL, middle, (tIndex<<1)+1)
        } else if nIndex > middle && nIndex <= tR {
            u(nIndex, nValue, middle+1, tR, (tIndex<<1)+2)
        }
        pushUp((tIndex<<1)+1, (tIndex<<1)+2, tIndex)
    }
    
    func sumRange(_ i: Int, _ j: Int) -> Int {
        return query(i, j, 0, nums.count-1, 0)
    }
    func query(_ l:Int, _ r:Int, _ queryL:Int, _ queryR:Int, _ treeIndex:Int) -> Int {
        if l == queryL && r == queryR {
            return tree[treeIndex]
        }
        let middle = (queryL+queryR)>>1
        if r <= middle {
            return query(l, r, queryL, middle, (treeIndex << 1)+1)
        } else if l > middle {
            return query(l, r, middle+1, queryR, (treeIndex<<1)+2)
        } else {
            return query(l, middle, queryL, middle, (treeIndex<<1)+1) + query(middle+1, r, middle+1, queryR, (treeIndex<<1)+2)
        }
    }
}


/**
 * Your NumArray object will be instantiated and called as such:
 * let obj = NumArray(nums)
 * obj.update(i, val)
 * let ret_2: Int = obj.sumRange(i, j)
 */
```

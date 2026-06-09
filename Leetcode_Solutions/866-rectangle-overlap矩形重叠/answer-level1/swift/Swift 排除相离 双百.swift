若 X2' <= X1 ,X1' >= X2 ,y1' >= y2 ,y2' <= y1 则肯定不行相交 其他情况都可能相交

func isRectangleOverlap(_ rec1: [Int], _ rec2: [Int]) -> Bool {
        if rec2[2] <= rec1[0] ||  rec2[0] >= rec1[2] || rec2[1] >= rec1[3] || rec2[3] <= rec1[1]{
            return false
        }
        return true
    }
之前用过二分法查找有序数列；现在是每次插入一个数据寻找位置尘埃落定。感觉效率不高～勉强通过
    var MedianFinder = function () {
        this.arr = []
    };


    MedianFinder.prototype.addNum = function (num) {
        arr = this.arr
        //递增arr,二分法插入num
        if (this.arr.length == 0) {
            this.arr.push(num)
            return
        }
        if (this.arr.length == 1) {
            if (this.arr[0] > num) {
                this.arr.unshift(num)
            } else {
                this.arr.push(num)
            }
            return
        }
        start = 0;
        end = this.arr.length - 1

        while (start <= end) {
            mid = (start + end) >> 1
            if (arr[mid] < num) {
                if (mid + 1 > end) {
                    arr.push(num)
                    return
                }
                if (num < arr[mid + 1]) {
                    arr.splice(mid + 1, 0, num)
                    return
                }
                start = mid + 1
            } else if (arr[mid] > num) {
                if (mid == 0) {
                    arr.unshift(num);
                    return
                }
                if (num > arr[mid - 1]) {
                    arr.splice(mid, 0, num)
                    return
                }
                end = mid - 1
            } else {
                arr.splice(mid, 0, num)
                return
            }
        }

    };


    MedianFinder.prototype.findMedian = function () {
        len = this.arr.length
        if (len % 2 == 0) {
            return (this.arr[(len) / 2] + this.arr[(len) / 2 - 1]) / 2
        } else {
            return (this.arr[(len - 1) / 2])
        }
    };
```
import "math"

type Bucket struct {
	MinVal, MaxVal int
	Set            bool
}

func maximumGap(nums []int) (rtn int) {
	var (
		i, bucketSize, bucketIdx, prevBucketMaxVal int
		minVal                                     = math.MaxInt32
		maxVal                                     = math.MinInt32
		length                                     = len(nums)
		buckets                                    = make([]Bucket, length+1)
	)

	switch length {
	case 0:
		fallthrough
	case 1:
		return 0
	case 2:
		if nums[0] > nums[1] {
			return nums[0] - nums[1]
		}
		return nums[1] - nums[0]
	}

	for i = 0; i < length; i++ {
		if nums[i] > maxVal {
			maxVal = nums[i]
		}
		if nums[i] < minVal {
			minVal = nums[i]
		}
	}

	if maxVal == minVal {
		return 0
	}

	bucketSize = (maxVal-minVal)/(length-1) + 1
	for i = 0; i < length; i++ {
		bucketIdx = (nums[i] - minVal) / bucketSize
		if buckets[bucketIdx].Set {
			if buckets[bucketIdx].MinVal > nums[i] {
				buckets[bucketIdx].MinVal = nums[i]
			}
			if buckets[bucketIdx].MaxVal < nums[i] {
				buckets[bucketIdx].MaxVal = nums[i]
			}
		} else {
			buckets[bucketIdx] = Bucket{
				MinVal: nums[i],
				MaxVal: nums[i],
				Set:    true,
			}
		}
	}

	prevBucketMaxVal = buckets[0].MaxVal
	if buckets[0].MinVal != maxVal {
		rtn = buckets[0].MaxVal - buckets[0].MinVal
	}
	for i = 1; i <= length; i++ {
		if !buckets[i].Set {
			continue
		}
		if buckets[i].MinVal-prevBucketMaxVal > rtn {
			rtn = buckets[i].MinVal - prevBucketMaxVal
		}
		prevBucketMaxVal = buckets[i].MaxVal
	}

	return
}

```

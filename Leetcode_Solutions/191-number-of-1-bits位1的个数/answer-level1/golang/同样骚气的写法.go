```
const (
	m1  uint32 = 0x55555555 //binary: 0101...
	m2  uint32 = 0x33333333 //binary: 00110011..
	m4  uint32 = 0x0f0f0f0f //binary:  4 zeros,  4 ones ...
	m8  uint32 = 0x00ff00ff //binary:  8 zeros,  8 ones ...
	m16 uint32 = 0x0000ffff //binary: 16 zeros, 16 ones ...
	m32 uint32 = 0x00000000 //binary: 32 zeros, 32 ones ...
	hff uint32 = 0xffffffff //binary: all ones
	h01 uint32 = 0x01010101 //the sum of 256 to the power of 0,1,2,3...
)

// ref: https://baike.baidu.com/item/%E6%B1%89%E6%98%8E%E9%87%8D%E9%87%8F
func hammingWeight(x uint32) int {
	x = (x & m1) + ((x >> 1) & m1)    //put count of each  2 bits into those  2 bits
	x = (x & m2) + ((x >> 2) & m2)    //put count of each  4 bits into those  4 bits
	x = (x & m4) + ((x >> 4) & m4)    //put count of each  8 bits into those  8 bits
	x = (x & m8) + ((x >> 8) & m8)    //put count of each 16 bits into those 16 bits
	x = (x & m16) + ((x >> 16) & m16) //put count of each 32 bits into those 32 bits
	return int(x)
}
```

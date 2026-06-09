### 解题思路
自己先实现了一个Fifo 之后使用自己实现的fifo来完成要求
### 代码

```golang
import "fmt"
type Fifo struct{
	array []int
	fifoCap int 
	fifoWriteIndex int 
	fifoReadIndex int
	fifoSize int
}

func (this *Fifo) FifoInit(fifoCap int) {
	this.fifoCap = fifoCap
	this.array = make([]int, this.fifoCap)
	this.fifoSize = 0
	this.fifoReadIndex = 0
	this.fifoWriteIndex = 0
}

//return error state
func (this *Fifo) FifoPush(x int) bool {
    if this.fifoCap <= this.fifoSize {
		return true
	}
	this.array[this.fifoWriteIndex] = x
	//fmt.Println(this.array)
	this.fifoWriteIndex = (this.fifoWriteIndex + 1) % this.fifoCap
	this.fifoSize++
	return false
}

//return pop value and error state
func (this *Fifo) FifoPop() (int, bool) {
	if this.fifoSize <= 0 {
		return 0, true
	}
	res := this.array[this.fifoReadIndex]
	this.fifoReadIndex = (this.fifoReadIndex + 1) % this.fifoCap
	this.fifoSize--
	//fmt.Println(this.array)
	return res, false
}

func (this *Fifo) FifoEmpty() bool {
	return this.fifoSize == 0
}

func (this *Fifo) FifoShow() {
	for offset := 0; offset < this.fifoSize; offset++ {
		showIdx := (this.fifoReadIndex + offset) % this.fifoCap
		fmt.Printf("%d<-", this.array[showIdx])
	}
	fmt.Printf("end fifoCap=%d fifoSize=%d\n", this.fifoCap, this.fifoSize)
}

func (this *Fifo) FifoSize() int {
	return this.fifoSize
}

type MyStack struct {
	FifoPair [2](*Fifo)
	FifoFlag bool  
}


/** Initialize your data structure here. */
func Constructor() MyStack {
	stackPtr := new(MyStack)
	stackPtr.FifoPair[0] = new(Fifo)
	stackPtr.FifoPair[1] = new(Fifo)
	stackPtr.FifoPair[0].FifoInit(100000)
	stackPtr.FifoPair[1].FifoInit(100000)
	stackPtr.FifoFlag = false
	return *stackPtr
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    if this.FifoFlag { // element in fifo[0]
		this.FifoPair[0].FifoPush(x)
	} else {
		this.FifoPair[1].FifoPush(x)
	}
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
	var fullFifo *Fifo
	var emptyFifo *Fifo

	if this.FifoFlag { // element in fifo[0]
		fullFifo = this.FifoPair[0]
		emptyFifo = this.FifoPair[1]
	} else {
		fullFifo = this.FifoPair[1]
		emptyFifo = this.FifoPair[0]
	}

    for fullFifo.FifoSize() > 1 {
		val, _ := fullFifo.FifoPop()
		emptyFifo.FifoPush(val)
	}

	val, _ := fullFifo.FifoPop()
	this.FifoFlag = !this.FifoFlag
    return val
}


/** Get the top element. */
func (this *MyStack) Top() int {
	var fullFifo *Fifo
	var emptyFifo *Fifo

	if this.FifoFlag { // element in fifo[0]
		fullFifo = this.FifoPair[0]
		emptyFifo = this.FifoPair[1]
	} else {
		fullFifo = this.FifoPair[1]
		emptyFifo = this.FifoPair[0]
	}

    for fullFifo.FifoSize() > 1 {
		val, _ := fullFifo.FifoPop()
		emptyFifo.FifoPush(val)
	}

	val, _ := fullFifo.FifoPop()
	emptyFifo.FifoPush(val)
	this.FifoFlag = !this.FifoFlag
    return val
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return this.FifoPair[0].FifoSize() == 0 && this.FifoPair[1].FifoSize() == 0
}
```
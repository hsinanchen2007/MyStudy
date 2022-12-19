
```golang
func dailyTemperatures(T []int) []int {
    if len(T) == 0 {
        return []int{}
    }
    result := make([]int, len(T)) 
    st := stack{make([]elem, len(T))}
    for i := 0; i < len(T); i++ {
        e := elem{
            index:  i,
            val:    T[i],
        }
        if len(st.data) > 0{
            topelem := st.top() 

            for topelem.val < e.val {
                result[topelem.index] = e.index - topelem.index 
                st.pop() 
                if len(st.data) == 0 {
                    break
                } 
                topelem = st.top()
            }    
        }  
        st.push(e)  
    }

    return result
}

type stack struct {
    data []elem 
}

func (st *stack) pop() {
    length := len(st.data)
    st.data = st.data[:length-1]
}

func (st *stack) top() elem {
    length := len(st.data) 
    return st.data[length-1]
}

func (st *stack) push(e elem) {
    st.data = append(st.data, e)
}

type elem struct {
    index   int
    val     int
}
```
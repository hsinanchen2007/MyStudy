Slices, on the other hand, are much more flexible, powerful, and convenient than arrays. Unlike arrays, slices can be resized using the built-in append function. Further, slices are reference types, meaning that they are cheap to assign and can be passed to other functions without having to create a new copy of its underlying array.
```
func reverseString(s []byte)  {
    r := []byte(s)
	for i, j := 0, len(r) - 1; i < len(r) / 2; i, j = i + 1, j - 1 {
		r[i], r[j] = r[j], r[i]
	}
}
```

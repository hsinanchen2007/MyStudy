```go
func complexNumberMultiply(a string, b string) string {
    var p, q, m, n int
    //buf := make([]byte, 200)
    fmt.Sscanf(a, "%d+%di", &p, &q)
    fmt.Sscanf(b, "%d+%di", &m, &n)
    return fmt.Sprintf("%d+%di", (p*m-q*n), (m*q+p*n))
}
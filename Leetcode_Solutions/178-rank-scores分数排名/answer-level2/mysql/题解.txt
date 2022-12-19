#利用临时变量来处理
SELECT
	t.score,
	CAST(t.Rank AS SIGNED) 'Rank'
FROM
	(
		SELECT
			s.score,
		IF (
			@a = s.score ,@rowno := @rowno ,@rowno := @rowno + 1
		) Rank,
		@a := s.score
	FROM
		Scores s,
		(
			SELECT
				(@rowno := 1),
				(
					@a := (SELECT MAX(score) FROM Scores)
				)
		) b
	ORDER BY
		s.score DESC
	) t
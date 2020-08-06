DOCO := readout-board-docs
PDF := ${DOCO}.pdf
TEX := ${DOCO}.tex
FIGS := figures/*

.PHONY: preview

all: ${PDF}

${PDF}: *.tex ${FIGS}
	pdflatex ${TEX}
	pdflatex ${TEX}
	pdflatex ${TEX}

preview:
	latexmk --shell-escape -pvc -pdf -interaction=nonstopmode $(TEX)

clean:
	rm -f *.aux *.nav *.out *.snm *.toc *.log *~ \#* *.fls *.fdb_latexmk *.glg *.glo *.gls *.ist *.xwm



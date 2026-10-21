# DatilografarHero

## Descrição

*DatilografarHero* é um jogo de agilidade e ritmo para terminal inspirado no estilo de jogabilidade de *Guitar Hero*, porém focado em habilidades de datilografia. Letras do alfabeto surgem aleatoriamente no topo da tela e caem em direções verticais em direção a uma barra localizada na parte inferior da interface.

## Objetivo

O objetivo do jogador é pressionar no teclado a tecla correspondente à letra em queda exatamente no momento em que ela atinge a linha de marcação na parte inferior da tela, acumulando acertos para avançar de fase e obter a maior pontuação possível.

## Funcionamento e Mecânicas Principais

### 1. Dinâmica de Queda e Coloração

* As letras são geradas aleatoriamente entre 'a' e 'z' e caem por uma de 4 posições horizontais possíveis ($x = 3, 6, 9, 12$).
* A cor da letra varia conforme sua posição vertical ($y$) em relação à linha alvo ($y = 10$):
  * **Vermelho:** Metade superior da trajetória ($y < 5$).
  * **Amarelo:** Metade inferior da trajetória até próximo do alvo ($5 \le y < 10$).
  * **Verde:** Exatamente sobre a linha alvo ($y = 10$).

### 2. Validação de Acertos e Erros

* **Acerto:** Pressionar a tecla correspondente no exato instante em que a letra se encontra sobre a linha verde ($y = 10$).
* **Erro:** Pressionar uma tecla incorreta, pressionar a tecla correta fora do tempo ($y \neq 10$), ou permitir que a letra passe da linha sem ser pressionada ($y > 10$).

### 3. Progressão de Fases e Dificuldade

* **Total de Letras por Fase:** Cada fase apresenta uma sequência de 21 letras (`maxLetras = 21`).
* **Critério de Avanço:** O jogador precisa obter no mínimo **10 acertos** por fase para ser aprovado.
* **Aumento de Dificuldade:** A cada fase concluída, a velocidade do jogo aumenta (o intervalo de atualização reduz em 50 ms a partir do valor inicial de 300 ms).

### 4. Sistema de Score e Histórico

Em caso de término de jogo (*Game Over*), o *Score* final é calculado com base nos acertos totais e no tempo decorrido do jogo pela fórmula:

$$
\text{Score} = \frac{\text{Acertos Totais} \times 10}{\text{Tempo (segundos)} - 20}
$$

* **Registros de Pontuação:** O nome do jogador (de até 4 caracteres) e o *Score* alcançado são persistidos no arquivo `scores.txt`.
* **Histórico da Partida:** O progresso de acertos em cada fase concluída é registrado temporariamente no arquivo `acertos.txt`.

## Regras do Jogo

* **Condição de Vitória da Fase:** Atingir ao menos 10 acertos dentre as 21 letras apresentadas na fase atual.
* **Condição de Game Over:** Não atingir a marca mínima de 10 acertos ao final das 21 letras de uma fase.

## Controles

### Ações durante a Partida

| Tecla | Ação |
| :--- | :--- |
| `A` a `Z` (Letras minúsculas) | Pressionar a tecla correspondente à letra em queda quando ela atingir a barra verde ($y = 10$). |
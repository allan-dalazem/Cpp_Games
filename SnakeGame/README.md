# SnakeGame

## Descrição

*SnakeGame* é uma adaptação para terminal do clássico jogo da cobrinha. O jogador controla um caractere em um campo delimitado por bordas, desviando de obstáculos gerados aleatoriamente e coletando itens para acumular pontos.

## Objetivo

O objetivo do jogo é guiar o personagem até as "maçãs" espalhadas pelo mapa para pontuar o máximo possível, evitando colidir com as paredes do mapa e com os obstáculos do cenário.

## Funcionamento e Mecânicas Principais

### 1. Campo de Jogo e Obstáculos

* O jogo se passa em uma grade de dimensão $39 \times 19$ posições úteis, delimitada por bordas sólidas (`Ü`, `ß`, `Û`).
* Ao iniciar a partida, **5 obstáculos** (`Û`) são gerados em posições aleatórias dentro do mapa.
* A posição dos obstáculos permanece fixa durante toda a partida.

### 2. Personagem e Movimentação

* O jogador é representado na cor verde e muda de caractere visual conforme a direção do movimento:
  * Movimento para Cima (`W`): representado por `v`
  * Movimento para Esquerda (`A`): representado por `>`
  * Movimento para Baixo (`S`): representado por `^`
  * Movimento para Direita (`D`): representado por `<`
* O personagem se move continuamente na direção selecionada a cada ciclo de atualização (intervalo de 300 ms).

### 3. Maçãs e Pontuação

* As maçãs são representadas por um caractere vermelho (`Ï`) gerado em posições aleatórias ($x \in [1, 39], y \in [1, 19]$).
* Sempre que o personagem ocupa a mesma posição da maçã:
  * A pontuação do jogador aumenta em **+1 ponto**.
  * A maçã é removida da posição atual e uma nova maçã é gerada em outro ponto aleatório do mapa.
* O placar atualizado é exibido continuamente na lateral da tela (`Pontos: X`).

## Regras do Jogo

* **Condição de Game Over:** O jogo é encerrado imediatamente se a cabeça do personagem colidir com:
  * As bordas superiores, inferiores ou laterais do mapa.
  * Qualquer um dos 5 obstáculos gerados no início do jogo.
* **Fim de Jogo:** Ao perder, o sistema exibe a mensagem de *Game Over!*, o *Score* final e solicita confirmação por tecla para encerrar a execução.

## Controles

### Movimentação

| Tecla | Ação |
| ----- | ----- |
| `W` / `w` | Mudar direção de movimento para Cima |
| `A` / `a` | Mudar direção de movimento para Esquerda |
| `S` / `s` | Mudar direção de movimento para Baixo |
| `D` / `d` | Mudar direção de movimento para Direita |

### Pós-Jogo / Encerramento

| Tecla | Ação |
| ----- | ----- |
| Qualquer tecla | Confirmar e fechar a aplicação na tela de *Game Over* |
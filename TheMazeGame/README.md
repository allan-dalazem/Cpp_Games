# TheMazeGame

## Descrição

*TheMazeGame* é um jogo de navegação em labirinto desenvolvido para terminal de comando. O jogador assume o controle do caractere `'x'` em um ambiente delimitado por blocos sólidos e precisa encontrar a saída do labirinto gerenciando o tempo decorrido e a quantidade de pontos restantes.

## Objetivo

O objetivo principal é guiar o personagem da posição inicial até o ponto de saída do labirinto antes que sua pontuação zerar. Cada movimento realizado e cada segundo transcorrido consomem a pontuação total do jogador.

## Funcionamento e Mecânicas Principais

### 1. Menu Principal e Registro de Jogador

Ao iniciar a aplicação, é apresentado um menu interativo com as seguintes opções:

1. **Jogar:** Inicia o fluxo de cadastro e partida.
2. **Scoreboard:** Exibe o histórico de pontuações registradas no arquivo `scores.txt`.
3. **Sair:** Encerra a execução do programa.

Antes de iniciar a partida, o jogador insere seu nome (limitado a **4 caracteres**), utilizado para registrar sua pontuação no ranking final.

### 2. Estrutura do Labirinto

* **Dimensões do Mapa:** Matriz de $19$ linhas por $29$ colunas.
* **Paredes:** Representadas pelo caractere ASCII `219` ($\text{Bloco Sólido}$).
* **Corredores Livres:** Representados por espaços em branco (`' '`).
* **Posição Inicial:** Coordenadas $(x = 1, y = 3)$.
* **Ponto de Saída (Vitória):** Coordenadas $(x = 27, y = 15)$.

### 3. Sistema de Pontuação e Cronômetro

* **Pontuação Inicial:** O jogador inicia a partida com $1000$ pontos.
* **Penalização de Pontos:** A pontuação sofre dedução de **5 pontos** sob duas condições acumulativas:
  * A cada movimento válido realizado (`W`, `A`, `S`, `D`).
  * A cada segundo de tempo real decorrido no cronômetro.
* **Cronômetro:** O tempo de partida é medido em segundos com precisão de duas casas decimais utilizando funções de tempo nativas (`gettimeofday`).

### 4. Cálculo do Score e Salvamento

Ao atingir com sucesso o ponto de saída $(27, 15)$, o *Score* final é calculado através da seguinte fórmula matemática:

$$
\text{Score} = (\text{Pontos Restantes} - \text{Tempo Decorrido}) \times 2
$$

* O valor final do *Score* é gravado juntamente com o nome do jogador no arquivo local `scores.txt`.

## Regras do Jogo

* **Condição de Vitória:** Chegar à posição de saída $(x = 27, y = 15)$ antes que os pontos cheguem a zero. O resultado é salvo no ranking global.
* **Condição de Derrota:** Ter a pontuação reduzida a zero ($\text{Pontos} \le 0$) antes de atingir a saída. O jogo exibe a mensagem de término e não registra a pontuação.

## Controles

### Navegação nos Menus

| Tecla | Ação |
| ----- | ----- |
| `W` / `w` | Mover personagem para **Cima** |
| `A` / `a` | Mover personagem para **Esquerda** |
| `S` / `s` | Mover personagem para **Baixo** |
| `D` / `d` | Mover personagem para **Direita** |

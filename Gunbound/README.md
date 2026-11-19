# Gunbound

## Descrição
*Gunbound* é um jogo de estratégia e artilharia por turnos para dois jogadores, inspirado no clássico Gunbound. Em arenas compostas por terreno destrutível, dois canhões se enfrentam em um confronto no formato Melhor de 3 (MD3).

## Objetivo
O objetivo do jogo é ajustar com precisão o ângulo, a força e a trajetória dos disparos para zerar os pontos de vida (100 HP) do canhão oponente antes de ser derrotado.

## Funcionamento e Mecânicas Principais

### 1. Escolha de Canhões
Antes de iniciar a partida, cada jogador seleciona um modelo de canhão, cada um apresentando características específicas de dano e sensibilidade ao vento:
- **Canhão Alfa:** Causa 35 de dano por acerto (necessita de 3 acertos para derrotar o oponente) e possui baixa sensibilidade ao vento.
- **Canhão Delta:** Causa 50 de dano por acerto (necessita de 2 acertos para derrotar o oponente) e possui sensibilidade média ao vento.
- **Canhão Ômega:** Causa 100 de dano por acerto (derrota o oponente com apenas 1 acerto) e possui altíssima sensibilidade ao vento.

### 2. Sistema de Vento Dinâmico
O vento altera sua direção e intensidade a cada rodada completa (após a jogada de ambos os jogadores). O sistema considera 8 direções possíveis (Norte, Sul, Leste, Oeste, Noroeste, Nordeste, Sudoeste e Sudeste) e uma intensidade entre 0 e 9. O vento afeta diretamente a trajetória do projétil de acordo com o nível de sensibilidade do canhão escolhido.

### 3. Fases do Turno
Cada turno de um jogador é dividido em três etapas sequenciais:
1. **Movimentação / Escavação:** O jogador pode se mover horizontalmente ou destruir terreno próximo (máximo de 5 ações por turno).
2. **Força (Gauge):** Um indicador oscilante determina a potência do tiro. O jogador deve travar a barra no momento desejado.
3. **Ajuste de Ângulo e Disparo:** Permite ajustar a inclinação da mira (de 0° a 360°, com variações de 5°) antes do lançamento.

### 4. Física e Terreno Destrutível
A trajetória do projétil obedece a um cálculo parabólico que considera a aceleração da gravidade ($g = 9.8$) e a influência do vetor do vento. Ao colidir com o cenário, o tiro destrói o terreno no ponto de impacto, alterando a geografia do mapa.

### 5. Pontuação e Registro
Ao término do confronto MD3, o *Score* do vencedor é calculado através da seguinte fórmula:

$$\text{Score} = \frac{\text{Canhão} \times \text{Vitórias} \times 2000}{\text{Total de Rounds}}$$

Os dados da partida e o nome do vencedor são gravados no arquivo `scores.txt`.

---

## Regras do Jogo
- **Condição de Vitória no Round:** Reduzir os pontos de vida (HP) do canhão oponente a 0 (HP inicial de 100).
- **Condição de Vitória na Partida:** Vencer 2 rounds em uma série de até 3 partidas (MD3).
- **Fogo Amigo:** Se o projétil atingir o próprio canhão que disparou, o jogador sofrerá o dano da sua própria arma.
- **Limite de Ações:** O jogador pode realizar no máximo 5 ações de movimentação ou escavação durante a fase inicial do seu turno.

---

## Controles

### Movimentação
| Tecla | Ação |
| :--- | :--- |
| `A` / `a` | Mover o canhão para a esquerda (consome 1 ação de movimento) |
| `D` / `d` | Mover o canhão para a direita (consome 1 ação de movimento) |

### Ações durante a Partida
| Tecla | Ação |
| :--- | :--- |
| `Q` / `q` | Escavar/destruir o terreno adjacente ao canhão (consome 1 ação) |
| `W` / `w` | Aumentar o ângulo de disparo em +5° (de 0° a 360°) |
| `S` / `s` | Diminuir o ângulo de disparo em -5° (de 0° a 360°) |
| `Barra de Espaço` | Travar a barra de força, confirmar ângulo e disparar, ou encerrar a movimentação |